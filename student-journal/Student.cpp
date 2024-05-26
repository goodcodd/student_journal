#include "Student.h"

int Student::student_id_counter = 0;

Student::Student(string first_name, string last_name, string middle_name)
    : Person(first_name, last_name, middle_name) {
    student_id = student_id_counter++;
}

int Student::getStudentId() const {
    return this->student_id;
};
