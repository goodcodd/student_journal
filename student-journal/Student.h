#pragma once

#include "Person.h"

using namespace std;

class Student : public Person {
private:
    int student_id;
    static int student_id_counter;

public:
    Student(string first_name, string last_name, string middle_name);

    int getStudentId() const;
};
