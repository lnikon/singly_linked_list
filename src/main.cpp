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

    list.push_front(-32);
    list.push_front(-143);

    list.traverse();
    std::cout << "\n";

    list.pop_front();

    list.traverse();
    std::cout << "\n";

    return 0;
}
