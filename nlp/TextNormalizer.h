#ifndef NORMALIZER_H 
#define NORMALIZER_H

// #define MAX_WORD_LEN 20

#include <string>
#include <vector>

class TextNormalizer { // Normalize text by removing unnecessary symbols
public:
    TextNormalizer() = delete;
    
    /**
     * Removing spaces, dots and commas.
     * Going through the all symbols and skeeps punctuation
     */
    static void removePunctuation(std::string& text);

    // Making all text with lower case
    static void lowerCase(std::string& text);

    // Converts string variable to the vector
    static std::vector<std::string> toVector(const std::string& text);
};

#endif