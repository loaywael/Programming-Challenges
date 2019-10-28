#include"Person.hpp"

int main(void){

    Person *john = new Person;
    
    john->SetName("ahmed");
    john->SetAge(21);
    cout << "first person name: " << john->GetName() << endl;
    cout << "first person age: " << john->GetAge() << endl;

    delete john;
}