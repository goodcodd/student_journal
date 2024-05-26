#include "Discipline.h"

Discipline::Discipline(string name) {
    this->name = name;
}

string Discipline::getName() const {
    return this->name;
}