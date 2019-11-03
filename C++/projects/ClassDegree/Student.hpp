#include <iostream>
#include <string>

using namespace std;

class Student{

    private:
        string firstName, lastName, address, city;
        int phoneNumber, age = 0;

    public:
        Student();
        Student(string firstName, string lastName, 
            string address, string city, int age, int number);
        ~Student();

        void setFisrtName(string name);
        string getFisrtName();

        void setLastName(string name);
        string getLastName();

        void setAddress(string address);
        string getAddres();

        void setCity(string name);
        string getCityName();

        void setAge(int age);
        int getAge();

        void setPhoneNumber(int number);
        int getPhoneNumber();

        void sitInClass();
};