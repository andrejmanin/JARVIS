#include <iostream>
#include <math.h>
#include "IntentRepository.h"

void IntentRepository::wordFrequency() {
    auto start = intents.begin();
    auto end = intents.end();
    while(start != end) {
        const std::vector<std::string>& keyWords = start->second.getKeyWords(); 
        for(const std::string& el : keyWords) {
            double uniq = uniqueIntents(el);
            if(uniq == 0) continue;
            wf[el] = log(((double)intents.size()) / (uniq)) + 1.0; // because if intents count will be equal to the uniq then we'll have 0 after log fuction, so for protection we add +1.0
        }
        start++;
    }
}

unsigned int IntentRepository::uniqueIntents(const std::string word) {
    auto start = intents.begin();
    auto end = intents.end();
    unsigned int count = 0;
    while(start != end) {
        std::vector<std::string> keyWords = start->second.getKeyWords();
        bool isUnique = false;
        for(std::string& e : keyWords) {
            if(e == word) {
                isUnique = true;
                break;
            }
        }
        if(isUnique) {
            count++;
        }
        start++;
    }
    return count;
}

IntentRepository::IntentRepository() {
    intents = { 
        {
            "Greeting",
            Intent {
                false, 
                {"hi", "hello", "morning", "evening", "ahoj", "cau", "hey"}, 
                {"Hi, how can I help you today?", "Hello, nice to see you! How can I help you?"}
            },
        },
        {   
            "HowAreYou",
            Intent {
                true,
                {"how", "are", "you", "do"},
                {"Today good!", "Better than yesterday.", "Good. How about you?", "Thank you for asking! I'm good.", "I thing better then yesterday. Thank you."}
            },
        },
        {
            "AboutBot",
            Intent {
                true,
                {"about", "you", "yourself", "tell"},
                {"I'm bot that can answer on diferent questions and help with your daily tasks."}
            }
        }
    };
    wordFrequency();
}

IntentRepository::~IntentRepository() {
    intents.clear();
}

void IntentRepository::writeIntent(const std::string intentName) {
    intents.insert({intentName, Intent {
        false,
        {},
        {}
    }});
}

void IntentRepository::writeIntent(const std::string intentName, bool question, std::vector<std::string> words, std::vector<std::string> answers){
    intents.insert({
        intentName, 
        Intent {
            question,
            words,
            answers
        }
    });
}

void IntentRepository::addKeyWord(const std::string intentName, const std::string word) {
    auto it = intents.find(intentName);
    it->second.addKeyWord(word);
    wordFrequency();
}

void IntentRepository::addKeyWord(const std::string intentName, const std::vector<std::string> words) {
    auto it = intents.find(intentName);
    it->second.addKeyWord(words);
    wordFrequency();
}

void IntentRepository::addAnswer(const std::string intentName, const std::string answer) {
    auto it = intents.find(intentName);
    it->second.addAnswer(answer);
}

void IntentRepository::addAnswer(const std::string intentName, const std::vector<std::string> answers) {
    auto it = intents.find(intentName);
    it->second.addAnswer(answers);
}

void IntentRepository::showIntents() {
    auto itr = intents.begin();
    while(itr != intents.end()) {
        std::cout << itr->first << " {"<< std::endl;
        std::vector<std::string> keyWords = itr->second.getKeyWords();
        std::vector<std::string> answers = itr->second.getAnswers();
        
        std::cout << "\tKey Words {" << std::endl;
        for(const std::string& el : keyWords) {
            std::cout << "\t\t\"" << el << "\",\n";
        }
        std::cout << "\t}" << std::endl;

        std::cout << "\tAnswers {" << std::endl;
        for(const std::string& el : answers) {
            std::cout << "\t\t\"" << el << "\",\n";
        }
        std::cout << "\t}" << std::endl;
        
        std::cout << "}" << std::endl;
        std::cout << std::endl;

        itr++;
    }
}

const std::map<std::string, Intent>& IntentRepository::getIntents() const {
    return intents;
}

const std::unordered_map<std::string, double>& IntentRepository::getWf() const {
    return wf;
}