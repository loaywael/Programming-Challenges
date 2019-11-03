#include "Course.hpp"


Course::Course(int numStudents, int numTeachers):
STUDENTS_SIZE(numStudents), TEACHERS_SIZE(numTeachers){}

Course::~Course(){
    delete[] students;
    delete[] teachers;
}