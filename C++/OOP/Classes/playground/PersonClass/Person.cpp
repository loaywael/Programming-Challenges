#include "Person.hpp"


Person::Person(){}; 

void Person::SetName(string name){
    // this->name === Person::name
    this->name = name;  // this === self
}

void Person::SetAge(int age){
    Person::age = age;
}

string Person::GetName(void){
    return this->name;
}

int Person::GetAge(void){
    return Person::age;
}