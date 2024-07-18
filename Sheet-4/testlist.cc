#include "linked_list.cc"
#include <iostream>

int main()
{
    List list;
    list.append(3);
    list.append(2);
    list.insert(list.first(), 1);

    for (Node *n = list.first(); n != 0; n = list.next(n))
    {
        std::cout << n->value << std::endl;
    }

    return 0;
}
