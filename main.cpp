#include <iostream>
#include <unordered_set>

#include "nlp/TextNormalizer.h"
#include "nlp/TrashWordsController.h"
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
    TrashWordsController controller;
    IntentRepository rep;
    IntentDetector detector(&rep);
    IntentResult res;

    const std::map<std::string, Intent>& intents = rep.getIntents();
    std::vector<std::string> v;
    std::string input;
    
    std::cout << "Enter someting...\n";
    do {
        std::cout << "You: ";
        std::getline(std::cin, input);
        if(input == "exit") {
            break;
        }

        TextNormalizer::removePunctuation(input);
        TextNormalizer::lowerCase(input);
        v = TextNormalizer::toVector(input);
        controller.trashCheck(v);
        res = detector.detect(v);

        auto begin = intents.begin();
        auto end = intents.end();
        while(begin != end) {
            if(begin->first == res.name) {
                std::cout << "Jarvis: " << begin->second.getAnswers()[0] << std::endl;
                break;
            }
            begin++;
        }
    } while(true);

    return 0;
}