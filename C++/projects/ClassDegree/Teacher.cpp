#include "Teacher.hpp"


Teacher::Teacher(){}

Teacher::Teacher(string firstName, string lastName, 
    string address, string city, int age, int number){
        setFisrtName(firstName);
        setLastName(lastName);
        setAddress(address);
        setCity(city);
        setPhoneNumber(number);
        setAge(age);
        cout << "Data Successfully initialized!";
}

Teacher::~Teacher(){}


void Teacher::setFisrtName(string name){
    this->firstName = name;
}

string Teacher::getFisrtName(){
    return firstName;
}


void Teacher::setLastName(string name){
    this->lastName = name;
}

string Teacher::getLastName(){
    return lastName;
}


void Teacher::setAddress(string address){
    this->address = address;
}

string Teacher::getAddres(){
    return address;
}


void Teacher::setCity(string name){
    this->city = city;
}

string Teacher::getCityName(){
    return city;
}


void Teacher::setAge(int age){
    this->age = age;
}

int Teacher::getAge(){
    return age;
}


void Teacher::setPhoneNumber(long int number){
    this->phoneNumber = number;
}

long int Teacher::getPhoneNumber(){
    return phoneNumber;
}


void Teacher::gradeStudent(){
    cout << "Student Graded!" << endl;
}


void Teacher::sitInClass(){
    cout << "Sitting at front of class!" << endl;
}
