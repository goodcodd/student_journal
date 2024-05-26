#include <iostream>
#include "Journal.h"

using namespace std;

void generateLessonsData(const vector<Lesson *> &lessons);

int main() {
    srand(time(nullptr));

    Student student1 = Student("Anastasiya", "Lytvyn", "Dmytrivna");
    Student student2 = Student("Janet", "Ibe", "Unanivna");
    Student student3 = Student("John", "Doe", "Smith");
    Student student4 = Student("Taras", "Melnyk", "Ivanovich");
    Student student5 = Student("Natalia", "Savchenko", "Petrovna");
    Student student6 = Student("Ivan", "Kovalchuk", "Oleksandrovich");
    Student student7 = Student("Olena", "Tkachenko", "Volodymyrivna");
    Student student8 = Student("Mykola", "Pavlenko", "Fedoryvich");
    Student student9 = Student("Kateryna", "Bondarenko", "Stepanivna");
    Student student10 = Student("Serhiy", "Zaytsev", "Oleksandrovich");
    Student student11 = Student("Yuliya", "Romanchuk", "Oleksiyovna");
    Student student12 = Student("Andriy", "Kostenko", "Volodymyrovych");
    Student student13 = Student("Tetyana", "Shevchuk", "Mykolayivna");

    Group group = Group("Group 1", vector<Student *>{
                            &student1, &student2, &student3, &student4, &student5, &student6,
                            &student7, &student8, &student9, &student10, &student11, &student12, &student13
                        });

    Journal journal = Journal(group, 2023, 2024, 2);

    Discipline *discipline1 = journal.addDiscipline("The teory of algorithms");
    Discipline *discipline2 = journal.addDiscipline("Programming");

    Teacher teacher1 = Teacher("Stepan", "Parashuk", "Dmytrovich", "IT department", "Candidate of Technical Sciences");
    Teacher teacher2 = Teacher("Konstantyn", "Surkov", "Yuirievich", "IT department",
                               "Candidate of Technical Sciences");

    Lesson *l1_1 = journal.addLesson(&group, discipline1, "01.05.2024", teacher1);
    Lesson *l1_2 = journal.addLesson(&group, discipline1, "03.05.2024", teacher1);
    Lesson *l1_3 = journal.addLesson(&group, discipline1, "05.05.2024", teacher1);
    Lesson *l1_4 = journal.addLesson(&group, discipline1, "08.05.2024", teacher1);
    Lesson *l1_5 = journal.addLesson(&group, discipline1, "10.05.2024", teacher1);
    Lesson *l1_6 = journal.addLesson(&group, discipline1, "12.05.2024", teacher1);
    Lesson *l1_7 = journal.addLesson(&group, discipline1, "15.05.2024", teacher1);
    Lesson *l1_8 = journal.addLesson(&group, discipline1, "17.05.2024", teacher1);
    Lesson *l1_9 = journal.addLesson(&group, discipline1, "19.05.2024", teacher1);

    const vector<Lesson *> lessons1 = {l1_1, l1_2, l1_3, l1_4, l1_5, l1_6, l1_7, l1_8, l1_9};
    generateLessonsData(lessons1);

    Lesson *l2_1 = journal.addLesson(&group, discipline2, "02.05.2024", teacher2);
    Lesson *l2_2 = journal.addLesson(&group, discipline2, "04.05.2024", teacher2);
    Lesson *l2_3 = journal.addLesson(&group, discipline2, "06.05.2024", teacher2);
    Lesson *l2_4 = journal.addLesson(&group, discipline2, "09.05.2024", teacher2);
    Lesson *l2_5 = journal.addLesson(&group, discipline2, "11.05.2024", teacher2);
    Lesson *l2_6 = journal.addLesson(&group, discipline2, "13.05.2024", teacher2);
    Lesson *l2_7 = journal.addLesson(&group, discipline2, "16.05.2024", teacher2);
    Lesson *l2_8 = journal.addLesson(&group, discipline2, "18.05.2024", teacher2);
    // another example of initialization method
    Lesson *l2_9 = journal.addLesson(group.getStudents(), discipline2, "20.05.2024", teacher2);

    const vector<Lesson *> lessons2 = {l2_1, l2_2, l2_3, l2_4, l2_5, l2_6, l2_7, l2_8, l2_9};
    generateLessonsData(lessons2);

    cout << journal;

    return 0;
}

void generateLessonsData(const vector<Lesson *> &lessons) {
    for (Lesson *lesson: lessons) {
        map<Student *, int> studentsInLesson = lesson->getStudentMarks();

        for (auto &studentMarkPair: studentsInLesson) {
            Student *student = studentMarkPair.first;

            bool isPresent = rand() % 3; // changes 1/2 of students to present

            lesson->setStudentPresence(student, isPresent);

            if (isPresent) {
                int mark = rand() % 5 + 1;
                lesson->markStudent(student, mark);
            } else {
                lesson->markStudent(student, 0);
            }
        }
    }
}
