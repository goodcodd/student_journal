#include "Journal.h"

#include <iomanip>

#include "Teacher.h"

using namespace std;

void Journal::checkForMaxLessons() const {
    if (MAX_LESSONS == this->lessons.size()) {
        cout << "Error: the program is currently supports only 1000 lessons at the same time.";
        exit(1);
    }
}

Journal::Journal(const Group &group, int start_study_year, int end_study_year, int cource_number): group(group),
                                                                                                   start_study_year(start_study_year), end_study_year(end_study_year), cource_number(cource_number) {
    this->disciplines = {};
    this->lessons = {};
    this->lessons.reserve(MAX_LESSONS);
}

Journal::~Journal() {
    this->disciplines.clear();
    this->lessons.clear();
}

Journal::Journal(const Journal &other): Journal(
    other.group, other.start_study_year, other.end_study_year, other.cource_number
) {
    this->disciplines = other.disciplines;
    this->lessons = other.lessons;
}

Journal &Journal::operator=(const Journal &other) {
    this->group = other.group;
    this->disciplines = other.disciplines;
    this->lessons = other.lessons;
    this->start_study_year = other.start_study_year;
    this->end_study_year = other.end_study_year;
    this->cource_number = other.cource_number;

    return *this;
}

Discipline *Journal::addDiscipline(const string &name) {
    this->disciplines.emplace_back(new Discipline(name));
    return this->disciplines.back();
}

Lesson *Journal::addLesson(Group *group, Discipline *discipline, const string &date_str, const Teacher &teacher) {
    this->checkForMaxLessons();
    this->lessons.emplace_back(group, discipline, date_str, teacher);
    return &this->lessons.back();
}

Lesson *Journal::addLesson(const vector<Student *> &students, Discipline *discipline, const Teacher &teacher) {
    this->checkForMaxLessons();
    this->lessons.emplace_back(students, discipline, teacher);
    return &this->lessons.back();
}

Lesson *Journal::addLesson(const vector<Student *> &students, Discipline *discipline, const string &date_str,
                           const Teacher &teacher) {
    this->checkForMaxLessons();
    this->lessons.emplace_back(students, discipline, date_str, teacher);
    return &this->lessons.back();
}

void Journal::removeLesson(Lesson *lessons_to_remove) {
    for (int i = 0; i < lessons.size(); i++) {
        if (&lessons[i] == lessons_to_remove) {
            lessons.erase(lessons.begin() + i);
            break;
        }
    }
}

Student *Journal::getStudentById(int student_id) const {
    for (Student *student: group.getStudents()) {
        if (student->getStudentId() == student_id) {
            return student;
        }
    }
    return nullptr;
}

ostream &operator<<(ostream &out, Journal &journal) {
    for (const Discipline *discipline: journal.disciplines) {
        out << "Discipline: " << discipline->getName() << "\n";

        vector<Lesson> disciplineLessons;
        for (const Lesson &lesson: journal.lessons) {
            if (lesson.getDiscipline() == discipline) {
                disciplineLessons.push_back(lesson);
            }
        }

        out << setw(22) << " ";
        for (const Lesson &lesson: disciplineLessons) {
            out << setw(2) << put_time(localtime(lesson.getDate()), "%d.%m") << " ";
        }
        out << "\n";

        out << setw(23) << " ";
        for (const Lesson &lesson: disciplineLessons) {
            out << "M" << setw(2) << "P" << setw(4) << " ";
        }
        out << "\n";

        map<int, pair<int, bool> > studentData;
        for (const Lesson &lesson: disciplineLessons) {
            auto marks = lesson.getStudentMarks();
            auto presence = lesson.getStudentPresence();
            for (const auto &mark: marks) {
                int studentId = mark.first->getStudentId();
                int studentMark = mark.second;
                bool studentPresence = presence[mark.first];
                studentData[studentId] = make_pair(studentMark, studentPresence);
            }
        }

        for (const auto &pair: studentData) {
            int studentId = pair.first;
            Student *student = journal.getStudentById(studentId);
            if (student != nullptr) {
                out << setw(15) << student->getLastName()
                        << " "
                        << student->getFirstLetterOfFirstName()
                        << ". "
                        << student->getFirstLetterOfMiddleName()
                        << ". "
                        << setw(1) << " ";
                for (const Lesson &lesson: disciplineLessons) {
                    auto marks = lesson.getStudentMarks();
                    auto presence = lesson.getStudentPresence();
                    if (marks.find(student) != marks.end()) {
                        out << marks[student] << setw(2) << (presence[student] ? " " : "N") << setw(4) << " ";
                    } else {
                        out << setw(10) << " " << " ";
                    }
                }
                out << "\n";
            }
        }
        out << "\n";
    }

    return out;
}
