#include "TextNormalizer.h"
#include <string.h>

void TextNormalizer::removePunctuation(std::string& text) {
    if(text.empty()) {
        return;
    }
    
    std::string res;
    res.reserve(text.size());

    bool prevSpace = false;
    int i = 0;
    for(char el : text) {
        if(el == ' ') {
            if(!prevSpace && i > 0) {
                prevSpace = true;
                res += el;
            }
        } else if(el == ',' || el == ':' || el == '.' || el == '?' || el == '!') {
            i++;
            continue;
        }
        else {
            res += el;
            prevSpace = false;
        }
        i++;
    }
    if(res.size() != 0) {
        if(res[res.size() - 1] == ' ')
            res.pop_back();
    }
    text = res;
}

void TextNormalizer::lowerCase(std::string& text) {
    std::string s = "";
    s.reserve(text.size());

    for(char el : text) {
        if(el >= 65 && el <= 90) {
            s += el + 32;
            continue; 
        }
        s += el;
    }
    text = s;
}

std::vector<std::string> TextNormalizer::toVector(const std::string& text) {    
    std::vector<std::string> result;
    std::string current;
    unsigned int size = text.size();
    for(unsigned int i = 0; i < size; i++) {
        if(text[i] == ' ') {
            if(!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else {
            current += text[i];
        }
    }

    if(!current.empty()) {
        result.push_back(current);
        current.clear();
    }
    
    return result;
}