#include <iostream>

#include "nlp/TextNormalizer.h"
#include "intent/Intent.h"

int main() {
    std::string s = " Hello,,,, World            !      How, are     you? a    ";
    std::cout << s << std::endl;
    
    TextNormalizer::removeSpacePunct(s);
    TextNormalizer::lowerCase(s);
    std::list<std::string> list = TextNormalizer::toList(s);
    
    std::cout << "{\n";
    int count = list.size();
    int i = 0;
    for(std::string el : list) {
        if(i != count - 1)
            std::cout << "   " << el << "," << std::endl;
        else 
            std::cout << "   " << el << std::endl;
        i++;
    }
    std::cout << '}' << std::endl;

    IntentRepository repository;
    repository.showIntents();

    return 0;
}