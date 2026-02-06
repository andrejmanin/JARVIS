#ifndef INTENT_DETECTOR
#define INTENT_DETECTOR

#include "IntentRepository.h"

#include <string>
#include <vector>

struct IntentResult {
    std::string name;
    double confidence;
};

class IntentDetector {
    IntentRepository* repository;
    
    unsigned int uniqueIntents(const std::string word);
public:
    IntentDetector(IntentRepository *repository); 
    IntentResult detect(std::vector<std::string> tokens);
};

#endif // INTENT_DETECTOR