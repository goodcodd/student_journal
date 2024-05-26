#pragma once

#include "Discipline.h"
#include "Group.h"
#include "Lesson.h"

using namespace std;

class Journal;

ostream &operator<<(ostream &out, Journal &t);

class Journal {
private:
    const int MAX_LESSONS = 100;

    Group group;
    vector<Discipline *> disciplines;
    vector<Lesson> lessons;
    int start_study_year;
    int end_study_year;
    int cource_number;

    void checkForMaxLessons() const;

public:
    Journal(const Group &group, int start_study_year, int end_study_year, int cource_number);

    ~Journal();

    Journal(const Journal &other);

    Journal &operator=(const Journal &other);

    Discipline *addDiscipline(const string &name);

    Lesson *addLesson(Group *group, Discipline *discipline, const string &date_str, const Teacher &teacher);

    Lesson *addLesson(const vector<Student *> &students, Discipline *discipline, const Teacher &teacher);

    Lesson *addLesson(const vector<Student *> &students, Discipline *discipline, const string &date_str,
                      const Teacher &teacher);

    void removeLesson(Lesson *lesson_to_remove);

    Student *getStudentById(int student_id) const;

    friend ostream &operator<<(ostream &out, Journal &t);
};
