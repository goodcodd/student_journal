#pragma once

#include <vector>

#include "Student.h"

using namespace std;

class Group {
private:
    string name;
    vector<Student *> students;

public:
    Group(string name);

    Group(string name, vector<Student *> students);

    vector<Student *> getStudents() const;

    void addStudent(Student *student);

    void removeStudent(const Student &student);
};
