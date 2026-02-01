#ifndef INTENT_REPOSITORY
#define INTENT_REPOSITORY

#include "Intent.h"

#include <map>
#include <vector>
#include <string>


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
    
    std::map<std::string, Intent>& getIntents();
};

#endif // INTENT_REPOSITORY