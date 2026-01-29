#include "Intent.h"

// ----------- Intent -----------
Intent::Intent(bool question, std::vector<std::string> keyWords, std::vector<std::string> answers) {
    isQuestion = question;
    this->keyWords = keyWords;
    this->answers = answers;
}

Intent::~Intent() {
    keyWords.clear();
    answers.clear();
    isQuestion = false;
}

void Intent::question() {
    isQuestion = true;
}

void Intent::addKeyWord(std::string word) {
    keyWords.push_back(word);
} 

void Intent::addKeyWord(std::vector<std::string> words) {
    int last = keyWords.size();
    int lastNew = words.size();
    int i = 0;
    while(last != lastNew) {
        last++;
        keyWords[last] = words[i];
        i++;
    }
}

void Intent::addAnswer(std::string answer) {
    answers.push_back(answer);
}

void Intent::addAnswer(std::vector<std::string> answers) {
    int last = this->answers.size();
    int lastNew = answers.size();
    int i = 0;
    while(last != lastNew) {
        last++;
        this->answers[last] = answers[i];
        i++;
    }
}

// ----------- IntentRepository -----------
IntentRepository::IntentRepository() {
    intents = { 
        {
            "Greeting",
            Intent {
                false, 
                {"hi", "hello", "morning", "evening", "ahoj", "cau", "hey"}, 
                {"hi, how can I help you today?", "hello, nice to see you! How can I help you?"}
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

void IntentRepository::writeIntent(std::string type, bool isQuestion, std::vector<std::string> words, std::vector<std::string> answers){
    intents.insert({
        type, 
        Intent {
            isQuestion,
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