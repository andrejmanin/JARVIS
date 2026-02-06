#ifndef TRASHWORDSCONTROLLER_H
#define TRASHWORDSCONTROLLER_H

#include <vector>
#include <string>

//  = { "a", "the", "and", "or", "on", "for" }
class TrashWordsController {
    std::vector<std::string> trashWords;

public:
    TrashWordsController();
    bool addWord(const std::string word);
    unsigned int addWord(const std::vector<const std::string> words);
    void removeWord(const std::string word);
    void removeWord(const std::vector<const std::string> words);
    std::vector<std::string> getWords();
};


#endif // TRASHWORDSCONTROLLER_H