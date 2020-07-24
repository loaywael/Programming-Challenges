#include<iostream>
#include<string>
using namespace std;

class Person{

    private:
        string name;
        int age;

    public:
        Person();
        void SetName(string name);
        string GetName(void);
        void SetAge(int age);
        int GetAge(void);

};