#pragma once

#include <map>

#include "Group.h"
#include "Discipline.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

class Lesson {
private:
    map<Student *, int> student_marks;
    map<Student *, bool> student_presence;
    Discipline *discipline;
    time_t date;

    const Teacher *teacher;

    static time_t getDateFromString(const string &date_str);

public:
    Lesson(Group *group, Discipline *discipline, const string &date_str, const Teacher &teacher);

    Lesson(const vector<Student *> &students, Discipline *discipline, const Teacher &teacher);

    Lesson(const vector<Student *> &students, Discipline *discipline, const string &date_str, const Teacher &teacher);

    void markStudent(Student *student, int mark);

    void setStudentPresence(Student *student, bool presence = false);

    const time_t *getDate() const;

    void setDate(time_t date);

    void setDate(const string &date_str);

    map<Student *, int> getStudentMarks() const;

    map<Student *, bool> getStudentPresence() const;

    Discipline *getDiscipline() const;

    bool operator<(const Lesson &other) const;
};
