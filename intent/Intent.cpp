#include "Intent.h"

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
    unsigned int wordsCount = words.size();
    for(int i = 0; i < wordsCount; i++) {
        keyWords.push_back(words[i]);
    }
}

void Intent::addAnswer(std::string answer) {
    answers.push_back(answer);
}

void Intent::addAnswer(std::vector<std::string> answers) {
    unsigned int answersCount = answers.size();
    for(int i = 0; i < answersCount; i++) {
        this->answers.push_back(answers[i]);
    }
}

const std::vector<std::string>& Intent::getKeyWords() const {
    return keyWords;
}

const std::vector<std::string>& Intent::getAnswers() const {
    return answers;
}

bool Intent::isQuestion() {
    return question;
}
