#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person;

ostream &operator<<(ostream &out, Person &human);

class Person {
private:
    string first_name;
    string last_name;
    string middle_name;

public:
    Person(string first_name, string last_name, string middle_name);

    string getFirstName() const;

    string getLastName() const;

    string getMiddleName() const;

    char getFirstLetterOfFirstName() const;

    char getFirstLetterOfMiddleName() const;
};
