#pragma once
#include "rules.h"
#include <vector>
#include <unordered_map>

class Radar{
private:
    vector<Rule*> rules;
    unordered_map<string, int> violations;
    unordered_map<string, int> fines;
    
public:

    void addRule(Rule* r);

    void checkForViolations(string plate, string date, CarType type, int speed, bool belt);
    
    void getAllFines();

    void getAllViolations();

};