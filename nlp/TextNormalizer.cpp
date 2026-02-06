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
    if(res[res.size() - 1] == ' ')
        res.pop_back();
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
    std::vector<std::string> v;
    int size = text.size();
    for(int i = 0, j = 0; i < size; i++) {
        if(text[i] == ' ' && i != 0) {
            v.push_back(text.substr(j, i - j));
            j = i + 1;
        } else if(text[i + 1] == *text.end() && j <= i) {
            v.push_back(text.substr(j, i - j + 1));
        }
    }

    return v;
}