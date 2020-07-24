#include <iostream>
using namespace std;


class basePerson{
    private:
    int _age;
    string _race;
    public:
        basePerson(){_age = 0;}
        string firstName, lastName;
        virtual void outputIdentity(void) = 0;
        virtual void outputAge(void){
            cout << "I'm " << _age << " years old" << endl;
        }
        void getPhone(void){
            cout << "phone: " << _phone << endl;
        } 

    protected: 
        long _phone = 00000000000000;
};


class Teacher: public basePerson{
    public:
        Teacher(const int& phone){_phone = phone;}
        void outputIdentity(void) override {
            cout << "I'm a teacher" << endl;
        }

        void outputAge(void) override{
            cout << "I'm a teacher" << endl;
            basePerson::outputAge();
        }
};


class Student: public basePerson{
    public:
        Student(const int& phone){_phone = phone;}
        void outputIdentity(void) override {
            cout << "I'm a student" << endl;
        }

        void outputAge(void) override{
            cout << "I'm a student" << endl;
            basePerson::outputAge();
        }
};

int main(void){
    Student john(9999999);
    john.firstName = "John";
    john.lastName = "Doe";

    Teacher zain(3333333);
    zain.firstName = "Zain";
    zain.lastName = "Zaffer";

    john.outputIdentity();
    zain.outputIdentity();
    john.outputAge();
    zain.outputAge();
    john.getPhone();
    zain.getPhone();
}