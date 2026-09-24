#pragma once

class SingleList
{
private:
    int data;
    SingleList *next;
public:
    SingleList(int data);
    static SingleList* create(int len);
};


