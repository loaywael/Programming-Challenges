#include <iostream>
using namespace std;

class Imagenary{

    private:
        int real, imagnary;
    public:
        // Imagenary();
        Imagenary(int x = 0, int y = 0): real{x}, imagnary{y}{}
        Imagenary operator + (Imagenary const &obj){
            Imagenary result;
            result.real = real + obj.real;
            result.imagnary = imagnary + obj.imagnary;
            return result;
        }
        void show(void){
            cout << real << " + i" << imagnary << endl;
        }    
};

int main(void){
    Imagenary n1{1, 1}, n2{3, 5};
    cout << "n1: ";
    n1.show();
    cout << "n2: ";
    n2.show(); 
    cout << endl;

    Imagenary result = n1 + n2;
    cout << "n1 + n2 = ";
    result.show();
    return 0;
}