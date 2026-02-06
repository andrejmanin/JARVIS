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
    std::cout << "LOG: UniqueIntents..." << std::endl;
    std::cout << "\t Word: " << word << std::endl;
    while(start != end) {
        std::vector<std::string> keyWords = start->second.getKeyWords();
        bool isUnique = false;
        for(std::string e : keyWords) {
            if(e == word) {
                std::cout << "\t Stop on intent: " << start->first << std::endl;
                isUnique = true;
                break;
            }
        }
        if(isUnique) {
            count++;
        }
        start++;
    }
    std::cout << "\t Total count: " << count << std::endl;
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
                    std::cout << "LOG: Intents size: " << intents.size();
                    std::cout << "\t unique: " << unique << "\t divide: " << (double)log((double)intents.size() / (double)unique) << std::endl;
                    idf += log((double)intents.size() / unique);
                    std::cout << "LOG: For word \"" << tokens[i] << "\" weight is = " << log((double)intents.size() / unique) << std::endl;
                }            
            }
        }

        std::cout << "LOG: For intent " << itr->first << " there is IDF = " << idf << std::endl;

        if(idf > bestScore) {
            bestScore = idf;
            intentName = itr->first;
        }
        itr++;
    }

    return IntentResult { intentName, bestScore };
}