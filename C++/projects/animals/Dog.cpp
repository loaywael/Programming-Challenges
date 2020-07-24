#include "Dog.hpp"

Dog::Dog(const string &name, const uint8_t &age)
    : Animal(name, age), ownerName("[None]"), ownerGender("[None]"), ownerAge(0){
        this->setClassType("Pet");
        this->setClassName("Dog");
        this->setNumLegs(4);
        cout << "Dog custom constructor is called!" << endl;
        cout << "=================================\n";
        cout << "class type: " << getClassType() << endl;
        cout << "class name: " << getClassName() << endl;
        cout << "owner name: " << ownerName << "\n" << "age: " << ownerGender << endl;
        cout << "owner age: " << +ownerAge << endl; 
        cout << "------------------------------\n";
    }

void Dog::setOwnerName(const string &name){
    this->ownerName = name;
}

string Dog::getOwnerName(void){
    return this->ownerName;
}

// -------------------------------------

void Dog::setOwnerGender(const string &gender){
    this->ownerGender = gender;
}

string Dog::getOwnerGender(void){
    return this->ownerGender;
}

// -------------------------------------

void Dog::setOwnerAge(const uint16_t &age){
    this->ownerAge = age;
}

uint16_t Dog::getOwnerAge(void){
    return this->ownerAge;
}

// -------------------------------------

Dog::~Dog(){
    cout << "------------------------------\n";
    cout << "deleted dog object references!" << endl;
}