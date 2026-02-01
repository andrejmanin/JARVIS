#include <iostream>
#include "IntentRepository.h"

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
                {"how", "are", "you"},
                {"Today good!", "Better than yesterday.", "Good. How about you?", "Thank you for asking! I'm good.", "I thing better then yesterday. Thank you."}
            },
        },
        {
            "AboutBot",
            Intent {
                true,
                {"about", "you"},
                {"I'm bot that can answer on diferent questions and help with your daily tasks."}
            }
        }
    };
}

IntentRepository::~IntentRepository() {
    intents.clear();
}

void IntentRepository::writeIntent(std::string type) {
    intents.insert({type, Intent {
        false,
        {},
        {}
    }});
}

void IntentRepository::writeIntent(std::string type, bool question, std::vector<std::string> words, std::vector<std::string> answers){
    intents.insert({
        type, 
        Intent {
            question,
            words,
            answers
        }
    });
}

void IntentRepository::addKeyWord(std::string type, std::string word) {
    auto it = intents.find(type);
    it->second.addKeyWord(word);
}

void IntentRepository::addKeyWord(std::string type, std::vector<std::string> words) {
    auto it = intents.find(type);
    it->second.addKeyWord(words);
}

void IntentRepository::addAnswer(std::string type, std::string answer) {
    auto it = intents.find(type);
    it->second.addAnswer(answer);
}

void IntentRepository::addAnswer(std::string type, std::vector<std::string> answers) {
    auto it = intents.find(type);
    it->second.addAnswer(answers);
}

void IntentRepository::showIntents() {
    auto itr = intents.begin();
    while(itr != intents.end()) {
        std::cout << itr->first << " {"<< std::endl;
        std::vector<std::string> keyWords = itr->second.getKeyWords();
        std::vector<std::string> answers = itr->second.getAnswers();
        
        std::cout << "\tKey Words {" << std::endl;
        for(std::string el : keyWords) {
            std::cout << "\t\t\"" << el << "\",\n";
        }
        std::cout << "\t}" << std::endl;

        std::cout << "\tAnswers {" << std::endl;
        for(std::string el : answers) {
            std::cout << "\t\t\"" << el << "\",\n";
        }
        std::cout << "\t}" << std::endl;
        
        std::cout << "}" << std::endl;
        std::cout << std::endl;

        itr++;
    }
}

std::map<std::string, Intent>& IntentRepository::getIntents() {
    return intents;
}