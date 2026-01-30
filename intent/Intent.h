#ifndef INTENT_H
#define INTENT_H

#include <map>
#include <vector>
#include <string>

class Intent {
    bool question;

    std::vector<std::string> keyWords;
    std::vector<std::string> answers;
public:
    Intent(bool question, std::vector<std::string> keyWords, std::vector<std::string> answers);
    ~Intent();
    
    void quest();
    void updateType(std::string t);
    void addKeyWord(std::string word);
    void addKeyWord(std::vector<std::string> words);
    void addAnswer(std::string answer);
    void addAnswer(std::vector<std::string> answers);
    std::vector<std::string> getKeyWords();
    std::vector<std::string> getAnswers();
    bool isQuestion();
};

#endif