#include "SingleList.h"

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vcruntime.h>

using namespace std;

Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
}

SingleList::SingleList(Node *head)
{
    this->head = head;
}

SingleList SingleList::create(int len)
{
    if (len <= 0)
    {
        return NULL;
    }
    Node *head = new Node(NULL);
    Node *prev = nullptr;
    Node *present = head;
    
    cout << "请输入各个结点的数值：" << endl; 
    for (int i = 0; i < len; i++)
    {
        int d;
        cin >> d;
        present->data = d;
        Node *tail = new Node(NULL);
        present->next = tail;
        prev = present;
        present = tail;
    }
    prev->next = nullptr;  // 将最后一个节点的尾巴去掉
    return SingleList(head);
}

int SingleList::get_length() const
{
    int count = 0;
    Node *ptr = this->head;
    while (ptr)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

bool SingleList::is_empty() const
{
    return this->get_length() == 0;
}

void SingleList::print() const
{
    if (this->is_empty())
    {
        cout << "单链表为空" << endl;
        return;
    }
    int len = get_length();
    Node *ptr = this->head;
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
    Node *ptr = this->head;
    Node *insert = new Node(d);  // 待插入的节点
    const int length = this->get_length();
    if (length == 0)
    {
        this->head = insert;
        return;
    }
    
    index = std::min(length, index);
    if (index == 0)
    {
        insert->next = ptr;
        this->head = insert;
        return;
    }
    
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }
    insert->next = ptr->next;
    ptr->next = insert;
}

Node* SingleList::find_kth(int k) const
{
    Node *ptr = this->head;
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
    Node *ptr = this->head;
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
        Node *old_head = this->head;
        this->head = old_head->next;  // 将这个链表的指针指向下一个节点（删除第0个）
        delete old_head;
        return;
    }
    
    Node *del_pre = this->find_kth(k - 1);  // 待删除的节点的前一个节点
    Node *to_del = del_pre->next;  // 待删除节点
    del_pre->next = to_del->next;
    delete to_del;
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

SingleList SingleList::reverse() const
{
    if (this->get_length() == 0)
    {
        return nullptr;
    }
    Node *prev = nullptr;
    Node *present = this->head; 
    
    while (present->next)
    {
        Node *next_node = present->next;
        present->next = prev;
        prev = present;
        present = next_node;
    }
    present->next = prev;
    return SingleList(present);
}

SingleList SingleList::merge(SingleList list1, SingleList list2)
{
    if (list1.get_length() == 0)
    {
        return list2;
    }
    if (list2.get_length() == 0)
    {
        return list1;
    }
    
    Node *ptr1 = list1.head;  // 第一个链表指针
    Node *ptr2 = list2.head;  // 第二个链表指针
    
    Node *merged_head = new Node(NULL);  // 合并的链表头
    Node *merged_ptr = merged_head;  // 合并的链表指针
    Node *merged_prev = nullptr;  // 指针前一个节点
    while (ptr1 && ptr2)
    {
        if (ptr1->data <= ptr2->data)
        {
            merged_ptr->data = ptr1->data;
            ptr1 = ptr1->next;
        }
        else
        {
            merged_ptr->data = ptr2->data;
            ptr2 = ptr2->next;
        }
        merged_ptr->next = new Node(NULL);
        merged_prev = merged_ptr;
        merged_ptr = merged_ptr->next;
    }

    // 两个链表若有剩余则全放在后面
    if (ptr1)
    {
        merged_prev->next = ptr1;
    }
    else if (ptr2)
    {
        merged_prev->next = ptr2;
    }
    
    return SingleList(merged_head);
}

SingleList SingleList::sort()
{
    Node *h = this->head;
    Node *ptr1 = h; 
    Node *ptr2;

    while (ptr1)
    {
        ptr2 = ptr1->next;
        while (ptr2)
        {
            // 若前指针大于后指针则交换两个节点的数据
            if (ptr1->data > ptr2->data)
            {
                int temp = ptr2->data;
                ptr2->data = ptr1->data;
                ptr1->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    
    return SingleList(h);
}


int main(int argc, char* argv[])
{
    cout << "请输入初始化链表的长度:" << endl;
    int len;
    cin >> len;
    SingleList list1 = SingleList::create(len);
    
    cout << "单链表如下：" << endl;
    list1.print();
    cout << endl;
    cout << "排序后为：" << endl;
    SingleList sorted_list1 = list1.sort();
    sorted_list1.print();
    cout << endl;
    
    cout << "请输入初始化链表的长度:" << endl;
    cin >> len;
    SingleList list2 = SingleList::create(len);
    cout << "第二个单链表如下：" << endl; 
    list2.print();
    cout << endl;
    cout << "排序后为:" << endl;
    SingleList sorted_list2 = list2.sort();
    sorted_list2.print();
    cout << endl;
    
    cout << "合并后链表为：" << endl;
    SingleList merged = SingleList::merge(list1, list2);
    merged.print();
    cout << endl;
    
    cout << "请输入插入结点的位置：" << endl;
    int index,data;
    cin >> index;
    cout<<"插入前单链表如下："<<endl; 
    list1.print();
    cout << endl << "请输入插入结点的数值：" << endl;
    cin >> data;
    list1.insert(index, data);
    cout << "插入后单链表如下：" << endl; 
    list1.print();
    cout << endl;
    
    cout << "请输入删除结点的位置：" << endl;
    cin >> index;
    cout << "删除前单链表如下：" << endl; 
    list1.print();
    list1.delete_kth(index);
    cout << endl << "删除后单链表如下：" << endl; 
    list1.print();
    cout << endl;
    
    cout << "请输入删除结点的数值：" << endl;
    cin >> data;
    cout << "删除前单链表如下：" << endl; 
    list1.print();
    list1.delete_n(data);
    cout << endl << "删除后单链表如下：" << endl; 
    list1.print();
    cout << endl;

    cout << "逆转单链表前,单链表如下：" << endl;
    list1.print();
    cout << endl << "逆转单链表后,单链表如下：" << endl;
    SingleList reversed = list1.reverse(); 
    reversed.print(); 
    
    return 0;
}