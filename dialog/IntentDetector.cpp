#include "IntentDetector.h"
#include <unordered_set>

IntentDetector::IntentDetector(IntentRepository* repository) {
    this->repository = repository;
}

IntentResult IntentDetector::detect(const std::vector<std::string>& tokens) {
    const std::map<std::string, Intent>& intents = repository->getIntents();
    auto itr = intents.begin();
    auto end = intents.end();
    double bestScore = 0.0;
    std::string intentName = "None";
    const std::unordered_map<std::string, double> wf = repository->getWf();
    while(itr != end) {
        const std::vector<std::string> keyWords = itr->second.getKeyWords();
        const std::unordered_set<std::string> keyWordSet(keyWords.begin(), keyWords.end());
        double score = 0.0;
        int count = tokens.size();
        
        for(const std::string& el : tokens) {
            if(keyWordSet.contains(el)) {
                score += wf.at(el);
            }
        }

        if(score > bestScore) {
            bestScore = score;
            intentName = itr->first;
        }
        itr++;
    }

    return IntentResult { intentName, bestScore };
}