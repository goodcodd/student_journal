#include "Lesson.h"

#include <iomanip>
#include <sstream>

Lesson::Lesson(Group *group, Discipline *discipline, const string &date_str, const Teacher &teacher) { // Add this constructor
    vector<Student *> students = group->getStudents();
    for (Student *student: students) {
        student_marks[student] = 0;
        student_presence[student] = true;
    }
    this->discipline = discipline;
    this->teacher = &teacher;
    this->date = Lesson::getDateFromString(date_str);
}

Lesson::Lesson(const vector<Student *> &students, Discipline *discipline, const Teacher &teacher) {
    for (Student *student: students) {
        student_marks[student] = 0;
        student_presence[student] = true;
    }
    this->discipline = discipline;
    this->teacher = &teacher;
    this->date = time(nullptr); // current time
}

Lesson::Lesson(const vector<Student *> &students, Discipline *discipline, const string &date_str, const Teacher &teacher) {
    for (Student *student: students) {
        student_marks[student] = 0;
        student_presence[student] = true;
    }
    this->discipline = discipline;
    this->teacher = &teacher;
    this->date = Lesson::getDateFromString(date_str);
}

void Lesson::markStudent(Student *student, int mark) {
    student_marks[student] = mark;
}

void Lesson::setStudentPresence(Student *student, bool presence) {
    student_presence[student] = presence;
}

const time_t* Lesson::getDate() const {
    return &this->date;
}

void Lesson::setDate(time_t date) {
    this->date = date;
}

time_t Lesson::getDateFromString(const string &date_str) {
    tm time = {0};
    stringstream ss(date_str);
    ss >> get_time(&time, "%d.%m.%Y");
    return mktime(&time);
}

void Lesson::setDate(const string &date_str) {
    this->date = Lesson::getDateFromString(date_str);
}

map<Student *, int> Lesson::getStudentMarks() const {
    return this->student_marks;
}

map<Student *, bool> Lesson::getStudentPresence() const {
    return this->student_presence;
}

Discipline * Lesson::getDiscipline() const {
    return this->discipline;
}

bool Lesson::operator<(const Lesson &other) const {
    return this->date < other.date;
}
