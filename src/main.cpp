#include <iostream>
#include <utility>

#include "singlylist.h"

int main()
{
    SinglyList<int> list;
    list.push_back(2);
    list.push_back(12);
    list.push_back(22);
    list.push_back(23);
    list.push_back(52);

    list.traverse();
    std::cout << "\n";

    SinglyList<int> list1(std::move(list));
    list1.traverse();

    return 0;
}
