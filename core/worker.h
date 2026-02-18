#include "nlp/TextNormalizer.h"
#include "nlp/TrashWordsController.h"
#include "intent/Intent.h"
#include "intent/IntentRepository.h"
#include "dialog/IntentDetector.h"

class Worker {
    IntentRepository rep;
    IntentResult res;
    TrashWordsController controller;
    const std::map<std::string, Intent>& intents = rep.getIntents();
public:
    Worker() = delete;
    
    IntentResult detectFromText(const std::string& text) {
        std::string line = text;
        IntentDetector detector(&rep);
        std::vector<std::string> v;

        TextNormalizer::removePunctuation(line);
        TextNormalizer::lowerCase(line);
        v = TextNormalizer::toVector(line);
        controller.trashCheck(v);
        return detector.detect(v);
    }

    const std::map<std::string, Intent>& getIntents() const {
        return intents;
    }

};