/*
 * Singleton.cpp
 *
 *  Created on: Nov 27, 2019
 *      Author: ezio
 */

#include <iostream>

class Person{
private:

	static Person* person;
	std::string name;
	int age;
	explicit Person(std::string, int age){
			this->name = name;
			this->age = age;
		}
public:
	int stats = 0;
	static Person* getInstance(){
		if (!person){
			person = new Person("Ahmed", 20);
		}
		return person;
	}

	void printAll(){
		std::cout << "name: " << name;
		std::cout << "age: " << age << std::endl;
	}
};

Person* Person::person;								// initialize the instance
int main(int argc, char** argv){
	Person* p = Person::getInstance();				// create/get instance from static method
	std::cout << "status: " << p->stats << "\t";	// access public attribute
	p->printAll();									// use regular method
	Person* p1 = Person::getInstance();
	std::cout << "p_Address: " << p << "\t" << "p1_Address: " << p1 << std::endl;
}
