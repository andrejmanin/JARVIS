#include "nlp/TextNormalizer.h"
#include "nlp/TrashWordsController.h"
#include "intent/Intent.h"
#include "intent/IntentRepository.h"
#include "dialog/IntentDetector.h"
#include <random>

class Worker {
    IntentRepository rep;
    IntentResult res;
    TrashWordsController controller;

    int randomNumber(const int maxNumber) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, maxNumber - 1);
        return dis(gen);
    } 
public:
    Worker() = default;
    
    std::string detectFromText(const std::string& text) {
        const std::map<std::string, Intent>& intents = rep.getIntents();
        std::string line = text;
        IntentDetector detector(&rep);
        std::vector<std::string> v;

        TextNormalizer::removePunctuation(line);
        TextNormalizer::lowerCase(line);
        v = TextNormalizer::toVector(line);
        controller.trashCheck(v);
        IntentResult res = detector.detect(v);
    
        auto begin = intents.begin();
        auto end = intents.end();
        while(begin != end) {
            if(begin->first == res.name) {
                int index = randomNumber(begin->second.getAnswers().size());
                if (index >= begin->second.getAnswers().size()) {
                    return begin->second.getAnswers()[0];
                }
                return begin->second.getAnswers()[index];
            }
            begin++;
        }
        return "None";
        
    }

    const std::map<std::string, Intent>& getIntents() const {
        return rep.getIntents();
    }

};