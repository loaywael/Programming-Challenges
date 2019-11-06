#include "Course.hpp"


Course::Course(int numStudents, int numTeachers):
STUDENTS_SIZE(numStudents), TEACHERS_SIZE(numTeachers){
    students = new Student [STUDENTS_SIZE];
    teachers = new Teacher [TEACHERS_SIZE];
}

Course::~Course(){
    delete[] students;
    delete[] teachers;
}
