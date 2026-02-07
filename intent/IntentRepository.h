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

    void writeIntent(const std::string intentName);
    void writeIntent(const std::string intentName, bool isQuestion, std::vector<std::string> words, std::vector<std::string> answers);
    void addKeyWord(const std::string intentName, const std::string word);
    void addKeyWord(const std::string intentName, const std::vector<std::string> words);
    void addAnswer(const std::string intentName, const std::string answer);
    void addAnswer(const std::string intentName, const std::vector<std::string> answers);
    void showIntents();
    
    const std::map<std::string, Intent>& getIntents() const;
    const std::unordered_map<std::string, double>& getWf() const;
};

#endif // INTENT_REPOSITORY