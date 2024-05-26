#include "Group.h"

Group::Group(string name) {
    this->name = name;
    this->students = vector<Student *>();
}

Group::Group(string name, vector<Student *> students) {
    this->name = name;
    this->students = students;
}

vector<Student *> Group::getStudents() const {
    vector<Student *> students_pointers;
    for (auto &student: this->students) {
        students_pointers.push_back(student);
    }
    return students_pointers;
}

void Group::addStudent(Student *student) {
    this->students.push_back(student);
}

void Group::removeStudent(const Student &studentToRemove) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getStudentId() == studentToRemove.getStudentId()) {
            students.erase(students.begin() + i);
            break;
        }
    }
}
