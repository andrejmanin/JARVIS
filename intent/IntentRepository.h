#ifndef INTENT_REPOSITORY
#define INTENT_REPOSITORY

#include "Intent.h"

#include <map>
#include <vector>
#include <string>
#include <unordered_map>


class IntentRepository {
private:
    std::map<std::string, Intent> intents;
    std::unordered_map<std::string, double> wf;

    void wordFrequency();
    unsigned int uniqueIntents(const std::string word);
public:
    IntentRepository();
    ~IntentRepository();

    void writeIntent(std::string intentName);
    void writeIntent(std::string intentName, bool isQuestion, std::vector<std::string> words, std::vector<std::string> answers);
    void addKeyWord(std::string intentName, std::string word);
    void addKeyWord(std::string intentName, std::vector<std::string> words);
    void addAnswer(std::string intentName, std::string answer);
    void addAnswer(std::string intentName, std::vector<std::string> answers);
    void showIntents();
    
    const std::map<std::string, Intent>& getIntents() const;
    const std::unordered_map<std::string, double>& getWf() const;
};

#endif // INTENT_REPOSITORY