#ifndef NORMALIZER_H 
#define NORMALIZER_H

// #define MAX_WORD_LEN 20

#include <string>
#include <vector>

class TextNormalizer { // Normalize text by removing unnecessary symbols
public:
    TextNormalizer() = delete;

    static void removeSpacePunct(std::string& text);
    // static void removePunctuation(std::string& text);
    static void lowerCase(std::string& text);
    static std::vector<std::string> toVector(std::string& text);
};

#endif