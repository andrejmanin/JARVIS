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

/**
 * Tasks to do:
 * 1. This "score" is not good:
 *       hello jarvis
 *       For intent: AboutBot there are 0 maches.
 *       2
 *      AboutBot score: 0
 *       For intent: Greeting there are 1 maches.
 *       7
 *       Greeting score: 0.142857 !!! <----- THERE SHOULD BE 0.99 OR 1
 *       For intent: HowAreYou there are 0 maches.
 *       3
 *       HowAreYou score: 0
 *       Hi, how can I help you today?
 * 2. Start adding Pythod part with voice and GPT API
 * 3. Clear project
 */