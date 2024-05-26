#pragma once

#include <string>

using namespace std;

class Discipline {
private:
    string name;

public:
    Discipline(string name);

    string getName() const;
};