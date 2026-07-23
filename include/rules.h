#pragma once
#include "helpers.h"
#include <string>

class Rule{
public:
    string violationType;

    Rule(string type);
    virtual ~Rule() = default;

    virtual Violation checkAndIssueFine(CarType type, int speed, bool belt) = 0;
};

class Seatbelt : public Rule {
public:
    Seatbelt();

    Violation checkAndIssueFine(CarType type, int speed, bool belt) override;
};

class Speeding : public Rule {
public:
    Speeding();

    Violation checkAndIssueFine(CarType type, int speed, bool belt) override;
};