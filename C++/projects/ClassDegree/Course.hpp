#include <iostream>
#include "Student.hpp"
#include "Teacher.hpp"
using namespace std;


class Course
{
    private:
        const int STUDENTS_SIZE, TEACHERS_SIZE;
        
    public:
        Course();
        Course(int numStudents, int numTeachers);
        Student *students = new Student [STUDENTS_SIZE];
        Teacher *teachers = new Teacher [TEACHERS_SIZE];
        ~Course();
    
};



