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

struct IntentResult {
    Intent intent;
    double confidence;
};

class IntentRepository {
    std::map<std::string, Intent> intents;
    
public:
    IntentRepository();
    ~IntentRepository();

    void writeIntent(std::string type);
    void writeIntent(std::string type, bool isQuestion, std::vector<std::string> words, std::vector<std::string> answers);
    void addKeyWord(std::string type, std::string word);
    void addKeyWord(std::string type, std::vector<std::string> words);
    void addAnswer(std::string type, std::string answer);
    void addAnswer(std::string type, std::vector<std::string> answers);
    void showIntents();
};

#endif