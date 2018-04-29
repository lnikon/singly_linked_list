#include <iostream>
#include <utility>

#include "singlylist.h"

int main()
{
    SinglyList<int> list1;
    
    // SinglyList<int>::Iterator it = list1.begin();
    list1.push_back(3);
    list1.push_back(98);
    list1.push_back(-1);

    std::cout << "traversing list1:\n";
    list1.traverse();

    // std::cout << "traversing list2:\n";
    // SinglyList<int> list2 = list1;
    // list2.traverse();
    
    // auto head = list2.front();
    
    // std::cout << head.data << std::endl;
    // list2.removeHead();
    
    // head = list2.front();
    // std::cout << head.data << std::endl;
    
    return 0;
}
