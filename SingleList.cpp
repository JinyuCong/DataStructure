#include "SingleList.h"

#include <iostream>
#include <string>
#include <vcruntime.h>

using namespace std;

SingleList::SingleList(int data)
{
    this->data = data;
    this->next = NULL;
}

SingleList* SingleList::create(int len)
{
    if (len <= 0)
    {
        return nullptr;
    }
    SingleList *head = new SingleList(NULL);
    SingleList *prev = NULL;
    SingleList *present = head;
    
    cout << "请输入各个结点的数值：" << endl; 
    for (int i = 0; i < len; i++)
    {
        int d;
        cin >> d;
        present->data = d;
        SingleList *tail = new SingleList(NULL);
        present->next = tail;
        prev = present;
        present = tail;
    }
    prev->next = nullptr;  // 将最后一个节点的尾巴去掉
    return head;
}

int SingleList::get_length()
{
    int count = 0;
    SingleList *ptr = this;
    while (ptr)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

bool SingleList::is_empty()
{
    return this->get_length() == 0;
}

void SingleList::print()
{
    if (this->is_empty())
    {
        cout << "单链表为空" << endl;
        return;
    }
    int len = get_length();
    SingleList *ptr = this;
    string out = "[";
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
        {
            out += std::to_string(ptr->data) + "]";
        }
        else
        {
            out += std::to_string(ptr->data) + " ";
            ptr = ptr->next;
        }
    }
    cout << out << endl;
}

void SingleList::insert(int index, int d)
{
    SingleList *ptr = this;
    SingleList *insert = new SingleList(d);  // 待插入的节点
    const int length = this->get_length();
    if (length == 0)
    {
        *this = *insert;
        return;
    }
    
    index = std::min(length, index);
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }
    insert->next = ptr->next;
    ptr->next = insert;
}

SingleList* SingleList::find_kth(int k)
{
    SingleList *ptr = this;
    if (k >= this->get_length())
    {
        throw out_of_range("k out of range");
    }
    for (int i = 0; i < k; ++i)
    {
        ptr = ptr->next;
    }
    return ptr;
}

int SingleList::find_n(int n)
{
    SingleList *ptr = this;
    int length = get_length();
    for (int i = 0; i < length; ++i)
    {
        if (ptr->data == n)
        {
            return i;
        }
        ptr = ptr->next;
    }
    return -1;
}

void SingleList::delete_kth(int k)
{
    if (this->is_empty())
    {
        cout << "单链表为空无法删除" << endl;
        return;
    }
    if (k == 0)
    {
        *this = *this->next;  // 将这个链表的指针指向下一个节点（删除第0个）
        return;
    }
    // 待删除的节点的前一个节点
    SingleList *del_pre = this->find_kth(k - 1);
    del_pre->next = del_pre->next->next;
}

void SingleList::delete_n(int n)
{
    int del_index = find_n(n);
    if (del_index == -1)
    {
        cout << "单链表不存在数值为" << n << "的节点" << endl;
        return;
    }
    this->delete_kth(del_index);
}

SingleList* SingleList::reverse()
{
    SingleList *prev = nullptr;
    SingleList *present = this; 
    
    while (present->next)
    {
        SingleList *next_node = present->next;
        present->next = prev;
        prev = present;
        present = next_node;
    }
    present->next = prev;
    return present;
}