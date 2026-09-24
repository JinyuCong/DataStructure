#include "SingleList.h"

#include <iostream>
#include <vcruntime.h>

using namespace std;

SingleList::SingleList(int data)
{
    this->data = data;
    this->next = NULL;
}


SingleList* SingleList::create(int len)
{
    SingleList *prev, *head, *tail;
    head = new SingleList(len);
    prev = head;
    if (len == 0)
    {
        goto end;
    }
    
    cout << "请输入各个节点的数值：" << endl;
    for (int i = 0; i < len; ++i)
    {
        int d;
        cin >> d;
        tail = new SingleList(d);
        prev->next = tail;
        prev = tail;
    }
    end: return head;
}
