#include <iostream>
#include <unordered_set>

#include "nlp/TextNormalizer.h"
#include "intent/Intent.h"
#include "intent/IntentRepository.h"
#include "dialog/IntentDetector.h"

int main() {
    // std::string s = " Hello,,,, World            !      How, are     you? a    ";
    std::string s = "Hello, Jarvis!";
    // std::cout << s << std::endl;
    
    TextNormalizer::removeSpacePunct(s);
    TextNormalizer::lowerCase(s);
    // std::cout << s << std::endl;
    std::vector<std::string> list = TextNormalizer::toVector(s);
    
    IntentRepository rep;
    
    IntentDetector detector(&rep);
    IntentResult res = detector.detect(list);

    auto intents = rep.getIntents().begin();
    auto end = rep.getIntents().end();
    while(intents != end) {
        if(intents->first == res.name) {
            std::cout << intents->second.getAnswers()[0] << std::endl;
            break;
        }
        intents++;
    }

    return 0;
}