#include "Student.hpp"


Student::Student(){}

Student::Student(string firstName, string lastName, 
    string address, string city, int age, int number){
        setFisrtName(firstName);
        setLastName(lastName);
        setAddress(address);
        setCity(city);
        setPhoneNumber(number);
        setAge(age);
        cout << "Data Successfully initialized!";
}

Student::~Student(){}


void Student::setFisrtName(string name){
    this->firstName = name;
}

string Student::getFisrtName(){
    return firstName;
}


void Student::setLastName(string name){
    this->lastName = name;
}

string Student::getLastName(){
    return lastName;
}


void Student::setAddress(string address){
    this->address = address;
}

string Student::getAddres(){
    return address;
}


void Student::setCity(string name){
    this->city = city;
}

string Student::getCityName(){
    return city;
}


void Student::setAge(int age){
    this->age = age;
}

int Student::getAge(){
    return age;
}


void Student::setPhoneNumber(int number){
    this->phoneNumber = number;
}

int Student::getPhoneNumber(){
    return phoneNumber;
}


void Student::sitInClass(){
    cout << "Sitting in main theater!" << endl;
}
