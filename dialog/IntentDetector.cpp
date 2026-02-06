#include "IntentDetector.h"
#include <unordered_set>
#include <iostream>
#include <math.h>

#define DBL_EPS 1e-12 

unsigned int IntentDetector::uniqueIntents(const std::string word) {
    std::map<std::string, Intent>& intents = repository->getIntents();
    auto start = intents.begin();
    auto end = intents.end();
    unsigned int count = 0;
    while(start != end) {
        std::vector<std::string> keyWords = start->second.getKeyWords();
        bool isUnique = false;
        for(std::string e : keyWords) {
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

IntentDetector::IntentDetector(IntentRepository* repository) {
    this->repository = repository;
}

IntentResult IntentDetector::detect(std::vector<std::string> tokens) {
    std::map<std::string, Intent>& intents = repository->getIntents();
    auto itr = intents.begin();
    auto end = intents.end();
    double bestScore = 0.0;
    std::string intentName = "None";
    
    while(itr != end) {
        std::vector<std::string> keyWords = itr->second.getKeyWords();
        std::unordered_set<std::string> keyWordSet(keyWords.begin(), keyWords.end());
        double idf = 0.0;

        int count = tokens.size();
        
        for(int i = 0; i < count; i++) {
            if(keyWordSet.contains(tokens[i])) {
                unsigned int unique = uniqueIntents(tokens[i]);
                if(unique != 0) {
                    idf += log((double)intents.size() / unique);
                }            
            }
        }

        if(idf > bestScore) {
            bestScore = idf;
            intentName = itr->first;
        }
        itr++;
    }

    return IntentResult { intentName, bestScore };
}