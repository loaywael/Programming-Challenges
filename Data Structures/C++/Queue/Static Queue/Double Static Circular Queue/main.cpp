#include <iostream>
#include "SCDeque.hpp"

int main(void){

    char ch;
        int item, head, tail, maxSize;
        std::cout << "Queue max-size: ";
        std::cin >> maxSize;
        SCDeque::Queue<int> Q(maxSize);

    while (1){
        
        std::cout << "Select operation number:" << std::endl;
        std::cout << "************************" << std::endl;
        std::cout << "1. insert new item from tail." << std::endl;
        std::cout << "2. insert new item from head." << std::endl;
        std::cout << "3. delete existing item from head." << std::endl;
        std::cout << "4. delete existing item from tail." << std::endl;
        std::cout << "5. display current items." << std::endl;
        std::cout << "6. get Queue head." << std::endl;
        std::cout << "7. get Queue tail." << std::endl;
        std::cout << "8. get Queue size." << std::endl;
        std::cout << "9. exite." << std::endl << std::endl;
        
        std::cout << "Select operation: ";
        std::cin >> ch;
        
        if (ch == '9'){break;}
        switch (ch){
            case '1':
                std::cout << "enter item value: ";
                std::cin >> item;
                Q.insertTail(item);
                break;

            case '2':
                std::cout << "enter item value: ";
                std::cin >> item;
                Q.insertHead(item);
                break;

            case '3':
                try{
                    item = Q.popHead();
                    std::cout << "popped the item: " << item << std::endl << std::endl;
                }
                catch (const char* e){
                    item = 0;
                    std::cerr << e << std::endl;
                }
                break;

            case '4':
                try{
                    item = Q.popTail();
                    std::cout << "popped the item: " << item << std::endl << std::endl;
                }
                catch (const char* e){
                    item = 0;
                    std::cerr << e << std::endl;
                }
                break;

            case '5':
            Q.display();
                break;

            case '6':
                try{
                    head = Q.getHead();
                    std::cout << "Queue Head: " << head << std::endl;
                    std::cout << std::endl;
                }
                catch (const char* e){
                    head = 0;
                    std::cerr << e << std::endl;
                }
                break;
            
            case '7':
                try{
                    head = Q.getTail();
                    std::cout << "Queue Tail: " << head << std::endl;
                    std::cout << std::endl;
                }
                catch (const char* e){
                    tail = 0;
                    std::cerr << e << std::endl;
                }
                break;
            
            case '8':
                std::cout << "Queue size: " << Q.getSize() << std::endl;
                std::cout << std::endl;
                break;

            // case '9':
            //     std::cout << "program ended!\n" << std::endl;
            //     return 0;
                

            default:
                std::cerr << "incorrect input! choose a correct number!\n\n";
                break;
        }
    }
    std::cout << "program ended!\n" << std::endl;
    return 0;
}