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
public:
    IntentDetector(IntentRepository *repository); 
    IntentResult detect(std::vector<std::string> tokens);
};

#endif // INTENT_DETECTOR