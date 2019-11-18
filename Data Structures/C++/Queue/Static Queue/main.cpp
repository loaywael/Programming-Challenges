#include <iostream>
#include "SQueue.h"

int main(void){

    char ch;
        int maxSize, item;

        std::cout << "Queue max-size: ";
        std::cin >> maxSize;
        SQueue::Queue<int> Q(maxSize);

    while (1){
        
        std::cout << "Select operation number:" << std::endl;
        std::cout << "************************" << std::endl;
        std::cout << "1. insert new item." << std::endl;
        std::cout << "2. delete existing item." << std::endl;
        std::cout << "3. display current items." << std::endl;
        std::cout << "4. get Queue head." << std::endl;
        std::cout << "5. get Queue tail." << std::endl;
        std::cout << "6. get Queue size." << std::endl;
        std::cout << "7. exite." << std::endl << std::endl;
        
        std::cout << "Select operation: ";
        std::cin >> ch;
        
        switch (ch){
            case '1':
                std::cout << "enter item value: ";
                std::cin >> item;
                Q.insert(item);
                break;

            case '2':
                item = Q.pop();
                std::cout << "popped the item: " << item << std::endl << std::endl;
                break;

            case '3':
            Q.display();
                break;

            case '4':
                std::cout << "Queue Head: " << Q.getHead() << std::endl;
                std::cout << std::endl;
                break;
            
            case '5':
                std::cout << "Queue Tail: " << Q.getTail() << std::endl;
                std::cout << std::endl;
                break;
            
            case '6':
                std::cout << "Queue size: " << Q.getSize() << std::endl;
                std::cout << std::endl;
                break;

            case '7':
                std::cout << "program ended!\n" << std::endl;
                return 0;
                

            default:
                std::cerr << "incorrect input! choose a correct number!\n\n";
                break;
        }
    }
    return 0;
}