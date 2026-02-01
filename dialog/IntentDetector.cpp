#include "IntentDetector.h"
#include <unordered_set>
#include <iostream>

#define DBL_EPS 1e-12 

IntentDetector::IntentDetector(IntentRepository* repository) {
    this->repository = repository;
}

IntentResult IntentDetector::detect(std::vector<std::string> tokens) {
    std::unordered_set<std::string> tokenSet(tokens.begin(), tokens.end());
    std::map<std::string, Intent>& intents = repository->getIntents();
    auto itr = intents.begin();
    auto end = intents.end();
    double bestScore = 0.0;
    std::string intentName = "None";

    while(itr != end) {
        int maches = 0;

        std::vector<std::string> keyWords = itr->second.getKeyWords();
        int count = keyWords.size();
        
        for(int i = 0; i < count; i++) {
            if(tokenSet.contains(keyWords[i])) {
                maches++;
            }
        }

        std::cout << "\tFor intent: " << itr->first << " there are " << maches << " maches." << std::endl;
        
        double score = 0.0;
        if(count != 0.0) {
            score = (double)maches / (double)count;
            std::cout << "\tCount: " << count << std::endl;
            const int roundingNum = 100;
            if(score - 0 < DBL_EPS * roundingNum * score) {
                score *= roundingNum * 100000;
                std::cout << "\tafter dbl_eps: " << (double)score << std::endl;
            }
        }
        std::cout << '\t' << itr->first << " score: " << (double)score << std::endl;

        if(score > bestScore) {
            bestScore = score;
            intentName = itr->first;
        }
        itr++;
    }

    return IntentResult { intentName, bestScore };
}