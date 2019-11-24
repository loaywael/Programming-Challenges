//============================================================================
// Name        : LinkedList.cpp
// Author      : Loay Wael
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++
//============================================================================

#include <iostream>

#include "LinkedList.hpp"


int main(int argc, char** argv){

    char ch;
    int item, idx;
    LinkedList::List<int> list;

    while (1){
        std::cout << "Select operation number:" << std::endl;
        std::cout << "************************" << std::endl;
        std::cout << "1. insert new item." << std::endl;
        std::cout << "2. append new item." << std::endl;
        std::cout << "3. delete existing item." << std::endl;
        std::cout << "4. find existing item." << std::endl;
        std::cout << "5. update list item." << std::endl;
        std::cout << "6. display list items." << std::endl;
        std::cout << "7. get list existing item." << std::endl;
        std::cout << "8. get list size." << std::endl;
        std::cout << "9. exite." << std::endl << std::endl;

        std::cout << "Select operation: ";
        std::cin >> ch;

        switch (ch){
            case '1':
                std::cout << "enter item value: ";
                std::cin >> item;
                std::cout << "enter item index: ";
                std::cin >> idx;
                list.insert(item, idx);
                break;

            case '2':
                std::cout << "enter item: ";
                std::cin >> item;
                list.insert(item);
                break;

            case '3':
                std::cout << "enter item index: ";
                std::cin >> idx;
                list.pop(idx);
                break;

            case '4':
                std::cout << "enter item: ";
                std::cin >> item;
                idx = list.find(item);
                std::cout << "found at index: " << idx << std::endl;
                break;

            case '5':
                std::cout << "enter item index: ";
                std::cin >> idx;
                std::cout << "enter item value: ";
                std::cin >> item;
                list.update(idx, item);
                break;

            case '6':
                list.display();
                break;

            case '7':
                try{
                    std::cout << "enter item index: ";
                    std::cin >> idx;
                    item = list.get(idx);
                    std::cout << "item value: " << item << std::endl;
                    std::cout << std::endl;
                }
                catch (const char* e){
                    item = 0;
                    std::cerr << e << std::endl;
                }
                break;

            case '8':
                std::cout << "list size: " << list.size() << std::endl;
                std::cout << std::endl;
                break;

            case '9':
                std::cout << "program ended!\n" << std::endl;
                return 0;


            default:
                std::cerr << "incorrect input! choose a correct number!\n\n";
                break;
        }
    }

    return 0;
}
