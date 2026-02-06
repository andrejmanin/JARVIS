#include <iostream>
#include <unordered_set>

#include "nlp/TextNormalizer.h"
#include "intent/Intent.h"
#include "intent/IntentRepository.h"
#include "dialog/IntentDetector.h"

void showVector(std::vector<std::string> v) {
    std::cout << "{ ";
    int count = v.size();
    for(int i = 0; i < count; i++) {
        std::cout << v[i] << ' '; 
    }
    std::cout << "}\n";
}

int main() {
    // std::string s = " Hello,,,, World            !      How, are     you? a    ";
    std::string input;
    std::cout << "Enter someting...\n";
    do {
        std::getline(std::cin, input);
        if(input == "exit") {
            break;
        }

        TextNormalizer::removeSpacePunct(input);
        TextNormalizer::lowerCase(input);
        std::vector<std::string> list = TextNormalizer::toVector(input);
        showVector(list);

        IntentRepository rep;
        IntentDetector detector(&rep);
        
        IntentResult res = detector.detect(list);
        
        auto intents = rep.getIntents().begin();
        auto end = rep.getIntents().end();
        while(intents != end) {
            if(intents->first == res.name) {
                std::cout << "========================================================\n";
                std::cout << "Jarvis: " << intents->second.getAnswers()[0] << std::endl;
                std::cout << "========================================================\n";
                break;
            }
            intents++;
        }
    } while(true);
    // std::string s = "Hello, Jarvis!";
    // std::cout << s << std::endl;
    
    // std::cout << s << std::endl;

    return 0;
}