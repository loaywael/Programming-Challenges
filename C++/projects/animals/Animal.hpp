#include <iostream>
#include <string>

using namespace std;

class Animal{

    private:
        string _className;
        string _classType;
        uint8_t _numLegs;
        
    public:
        string name;
        uint16_t age;
        string statu;

        Animal();
        Animal(const string &name, const uint8_t &age);

    protected:
        void setClassName(const string &name);
        string getClassName(void);

        void setClassType(const string &type);
        string getClassType(void);

        void setNumLegs(const uint16_t &legs);
        uint16_t getNumLegs(void);
};