#ifndef NORMALIZER_H 
#define NORMALIZER_H

// #define MAX_WORD_LEN 20

#include <string>
#include <list>

class TextNormalizer { // Hello, How are you?
public:
    TextNormalizer() = delete;
    /**
     * Those functions will return 
     *  - 0 if they were compleated successfully
     *  - 1 if there was some problems
     */
    static void removeSpacePunct(std::string& text);
    // static void removePunctuation(std::string& text);
    static void lowerCase(std::string& text);
    static std::list<std::string> toList(std::string& text);
};

#endif