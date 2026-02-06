#include <algorithm>
#include "TrashWordsController.h"

TrashWordsController::TrashWordsController() {
    trashWords = { "a", "the", "and", "or", "on", "for" };
}

bool TrashWordsController::addWord(const std::string word) {
    int result = std::find(trashWords.begin(), trashWords.end(), word) - trashWords.begin();

    if(result == trashWords.size()) {
        trashWords.push_back(word);
        return true;
    }
    return false;
}

unsigned int TrashWordsController::addWord(const std::vector<std::string> words) {
    unsigned int count = 0;
    for(const std::string el : words) {
        if(addWord(el)) {
            count++;
        }
    }
    return count;
}

void TrashWordsController::removeWord(const std::string word) {
    auto result = std::find(trashWords.begin(), trashWords.end(), word);
    if(result != trashWords.end()) {
        trashWords.erase(result);
    }
}

void TrashWordsController::removeWord(const std::vector<std::string> words) {
    if(words.size() == 0)
        return;

    for(std::string el : words) {
        removeWord(el);
    }
}

std::vector<std::string> TrashWordsController::getWords() {
    return trashWords;
}

bool TrashWordsController::compare(const std::string word) {
    for(std::string el : trashWords) {
        if(el == word)
            return true;
    }
    return false;
}

void TrashWordsController::trashCheck(std::vector<std::string>& v) {
    auto start = v.begin();
    auto end = v.end();
    while(start != end) {
        if(compare(*start)) {
            v.erase(start);
        }
        start++;
    }
}