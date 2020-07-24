#include <iostream>
#include <string>

using namespace std;

class Teacher{

    private:
        string firstName, lastName, address, city;
        long int phoneNumber, age = 0;

    public:
        Teacher();
        Teacher(string firstName, string lastName, string address, string city, int age, int number);
        ~Teacher();

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

        void setPhoneNumber(long int number);
        long int getPhoneNumber();

        void gradeStudent();
        void sitInClass();

};