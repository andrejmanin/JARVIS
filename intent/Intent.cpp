#include "Intent.h"
#include <iostream>

Intent::Intent(bool question, std::vector<std::string> keyWords, std::vector<std::string> answers) {
    this->question = question;
    this->keyWords = keyWords;
    this->answers = answers;
}

Intent::~Intent() {
    keyWords.clear();
    answers.clear();
    question = false;
}

void Intent::quest() {
    question = true;
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

std::vector<std::string> Intent::getKeyWords() {
    return keyWords;
}

std::vector<std::string> Intent::getAnswers() {
    return answers;
}

bool Intent::isQuestion() {
    return question;
}
