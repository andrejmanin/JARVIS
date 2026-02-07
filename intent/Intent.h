#ifndef INTENT_H
#define INTENT_H

#include <map>
#include <vector>
#include <string>

class Intent {
private:
    bool question;

    std::vector<std::string> keyWords;
    std::vector<std::string> answers;
public:
    Intent(bool question, const std::vector<std::string> keyWords, const std::vector<std::string> answers);
    ~Intent();
    
    void quest();
    void updateType(const std::string t);
    void addKeyWord(const std::string word);
    void addKeyWord(const std::vector<std::string> words);
    void addAnswer(const std::string answer);
    void addAnswer(const std::vector<std::string> answers);
    const std::vector<std::string>& getKeyWords() const;
    const std::vector<std::string>& getAnswers() const;
    bool isQuestion();
};

#endif