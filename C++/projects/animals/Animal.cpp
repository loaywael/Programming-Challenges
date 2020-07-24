#include "Animal.hpp"



Animal::Animal()
    :name("[none]"), statu("[none]"), age(0){
    cout << "default constructor called" << endl;
    cout << "=================================\n";
    cout << "name: " << name << "\n" << "age: " << +age << endl;
    cout << "statu: " << statu << endl; 
    cout << "------------------------------\n";
}

Animal::Animal(const string &name, const uint8_t &age){
    cout << "Animal custom constructor called" << endl;
    cout << "=================================\n";
    this->name = name;
    this->statu = "normal";
    this->age = age;
    cout << "name: " << name << "\n" << "age: " << +age << endl;
    cout << "statu: " << statu << endl; 
    cout << "------------------------------\n";
}


void Animal::setClassName(const string &name){
    this->_className = name;
}

string Animal::getClassName(void){
    return this->_className;
}

// -------------------------------------

void Animal::setClassType(const string &type){
    this->_classType = type;
}

string Animal::getClassType(void){
    return this->_classType;
}

// -------------------------------------

void Animal::setNumLegs(const uint16_t &legs){
    this->_numLegs = legs;
}

uint16_t Animal::getNumLegs(void){
    return this-> _numLegs;
}

// -------------------------------------
