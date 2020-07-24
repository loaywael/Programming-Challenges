#include "Dog.hpp"

int main(void){

    Dog *dog = new Dog("Puppy", 3);

    dog->setOwnerName("Zain");
    dog->setOwnerGender("Male");
    dog->setOwnerAge(30);
    dog->statu = "happy";

    cout << "called in main!" << endl;
    cout << "=================================\n";
    cout << "owner name: " << dog->getOwnerName() << endl;
    cout << "owner gender: " << dog->getOwnerGender() << endl;
    cout << "owner age: " << dog->getOwnerAge() << endl;
    cout << "animal statu: " << dog->statu << endl;

    delete dog;
    return 0;
}