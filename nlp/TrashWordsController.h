#ifndef TRASHWORDSCONTROLLER_H
#define TRASHWORDSCONTROLLER_H

#include <vector>
#include <string>

//  = { "a", "the", "and", "or", "on", "for" }
class TrashWordsController {
    std::vector<std::string> trashWords;
    bool compare(const std::string word);
public:
    // Adds basic "trash words" to the vector
    TrashWordsController();
    /**
     * Returns state of added "trash words"
     * - true - if word was added
     * - false - if word wasn't added
     *  */  
    bool addWord(const std::string word);
    // Returns count of added "trash words" 
    unsigned int addWord(const std::vector<std::string> words);
    void removeWord(const std::string word);
    void removeWord(const std::vector<std::string> words);
    std::vector<std::string> getWords();

    void trashCheck(std::vector<std::string>& v);
};


#endif // TRASHWORDSCONTROLLER_H