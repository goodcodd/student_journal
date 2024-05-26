#include "Teacher.h"

int Teacher::teacher_id_counter = 0;

Teacher::Teacher(string first_name, string last_name, string middle_name, string department, string degree): Person(
    first_name, last_name, middle_name
) {
    this->department = department;
    this->degree = degree;
    this->teacher_id = teacher_id_counter++;
}

string Teacher::getDepartment() const {
    return this->department;
}

string Teacher::getDegree() const {
    return this->degree;
}

int Teacher::getTeacherId() const {
    return this->teacher_id;
}

ostream &operator<<(ostream &out, Teacher &t) {
    out << t.getFirstName() << " " << t.getMiddleName() << " " << t.getLastName();
    out << ", " << t.department << ", " << t.degree;
    return out;
}
