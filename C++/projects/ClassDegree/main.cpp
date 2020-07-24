#include "Course.hpp"

int main(void){
    Course CPP(3, 1);
    CPP.students[0].setFisrtName("John");
    CPP.students[0].setLastName("Doe");
    CPP.students[0].setAddress("Michigan, US");
    CPP.students[0].setCity("Michigan");
    CPP.students[0].setPhoneNumber(123);
    CPP.students[0].setAge(30);

    CPP.students[1].setFisrtName("Will");
    CPP.students[1].setLastName("Smith");
    CPP.students[1].setAddress("San-Fransisco, US");
    CPP.students[1].setCity("San-Fransisco");
    CPP.students[1].setPhoneNumber(368);
    CPP.students[1].setAge(24);

    CPP.students[2].setFisrtName("Marry");
    CPP.students[2].setLastName("Roger");
    CPP.students[2].setAddress("Michigan, US");
    CPP.students[2].setCity("Michigan");
    CPP.students[2].setPhoneNumber(455);
    CPP.students[2].setAge(27);

    CPP.teachers[0].setFisrtName("Zain");
    CPP.teachers[0].setLastName("Ramey");
    CPP.teachers[0].setAddress("Los Angeles, US");
    CPP.teachers[0].setCity("Los Angeles");
    CPP.teachers[0].setPhoneNumber(578);
    CPP.teachers[0].setAge(50);


    cout << "Intermediate C++" << endl;
    CPP.teachers[0].gradeStudent();
    

    return 0;
}