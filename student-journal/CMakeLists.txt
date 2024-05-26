cmake_minimum_required(VERSION 3.28)
project(student_journal)

set(CMAKE_CXX_STANDARD 17)

add_executable(student_journal main.cpp
        Group.h
        Group.cpp
        Person.h
        Person.cpp
        Journal.h
        Journal.cpp
        Lesson.cpp
        Lesson.h
        Student.h
        Teacher.h
        Teacher.cpp
        DIscipline.h
        Discipline.cpp
        Student.cpp)
