#include "Animal.hpp"

class Dog: public Animal{

    private:
        string ownerName, ownerGender;
        uint16_t ownerAge;
        
    public:
        Dog();
        ~Dog();
        Dog(const string &name, const uint8_t &age);
        void setOwnerName(const string &name);
        string getOwnerName(void);

        void setOwnerGender(const string &gender);
        string getOwnerGender(void);

        void setOwnerAge(const uint16_t &age);
        uint16_t getOwnerAge(void);
};