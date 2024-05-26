#include "Person.h"

Person::Person(string first_name, string last_name, string middle_name)
    : first_name(first_name), last_name(last_name), middle_name(middle_name) {}

string Person::getFirstName() const {
    return first_name;
}

string Person::getLastName() const {
    return last_name;
}

string Person::getMiddleName() const {
    return middle_name;
}

char Person::getFirstLetterOfFirstName() const {
    return first_name[0];
}

char Person::getFirstLetterOfMiddleName() const {
    return middle_name[0];
}

ostream &operator<<(ostream &out, Person &human) {
    out << human.getFirstName() << " " << human.getMiddleName() << " " << human.getLastName();
    return out;
}
