#include "SingleList.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    SingleList *l = SingleList::create(0);
    l->insert(0, 200);
    l->print();
    // SingleList *reversed = l->reverse();
    // reversed->print();
    return 0;
}
