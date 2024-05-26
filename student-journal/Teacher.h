#pragma once
#include "Person.h"

class Teacher;

ostream &operator<<(ostream &out, Teacher &t);

class Teacher : public Person {
private:
    int teacher_id;
    static int teacher_id_counter;
    string department; // кафедра (наприклад, "Кафедра інформаційних технологій")
    string degree;

public:
    Teacher(string first_name, string last_name, string middle_name, string department, string degree);

    string getDepartment() const;

    string getDegree() const;

    int getTeacherId() const;

    friend ostream &operator<<(ostream &out, Teacher &t);
};
