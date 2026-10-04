#include "DoubleList.h"
#include <iostream>
using namespace std;

Node::Node(int data, Node* prev, Node* next)
{
    this->data = data;
    this->prev = prev;
    this->next = next;
}

DoubleList::DoubleList(Node* head)
{
    this->head = head;
}

DoubleList DoubleList::create(int n)
{
    if (n == 0)
    {
        return nullptr;
    }
    Node *head = new Node();
    Node *curr = head;
    int data;
    
    cout << "please enter values of each node: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> data;
        curr->data = data;
        Node *new_node = new Node();
        curr->next = new_node;
        new_node->prev = curr;
        curr = new_node;
    }
    curr->prev->next = nullptr;
    return DoubleList(head);
}

void DoubleList::print() const
{
    Node *curr = this->head;
    while (curr)
    {
        if (!curr->next)
        {
            cout << curr->data << endl;
        }
        else
        {
            cout << curr->data << "<->";
        }
        curr = curr->next;
    }
}

int DoubleList::get_length() const
{
    int len = 0;
    Node *curr = this->head;
    while (curr)
    {
        len++;
        curr = curr->next;
    }
    return len;
}

bool DoubleList::is_empty() const
{
    return get_length() == 0;
}

Node* DoubleList::find_kth(int k) const
{
    Node* curr = head;
    for (int i = 0; i < k; ++i)
    {
        curr = curr->next;
    }
    return curr;
}

int DoubleList::find_n(int n) const
{
    Node *curr = head;
    int index = 0;
    while (curr)
    {
        if (curr->data == n)
        {
            return index;
        }
        curr = curr->next;
        index++;
    }
    return -1;
}

void DoubleList::insert_after_node(Node* prev_node, Node* insert_node)
{
    Node *origin_next_node = prev_node->next;  // 存储原始双链表的prev_node的后一个节点
    prev_node->next = insert_node;
    insert_node->prev = prev_node;
    insert_node->next = origin_next_node;
    if (origin_next_node != nullptr)
    {
        origin_next_node->prev = insert_node;
    }
}

void DoubleList::insert_after_index(int index, Node* insert_node)
{
    if (this->is_empty())
    {
        this->head = insert_node;
    }
    int length = get_length();
    index = min(index, length - 1);
    Node *prev_node = this->find_kth(index);
    insert_after_node(prev_node, insert_node);
}

void DoubleList::delete_node(Node* to_delete)
{
    if (this->get_length() == 0)
    {
        cout << "Void list can't delete a node." << endl;
        return;
    }

    if (!to_delete->prev && !to_delete->next)
    {
        this->head = nullptr;
        delete to_delete;
        return;
    }
    
    // 若删除第一个节点
    if (!to_delete->prev)
    {
        to_delete->next->prev = nullptr;
        this->head = to_delete->next;
        
    }
    // 若删除最后一个节点
    else if (!to_delete->next)
    {
        to_delete->prev->next = nullptr;
    }
    // 若删除中间节点
    else
    {
        to_delete->prev->next = to_delete->next;
        to_delete->next->prev = to_delete->prev;
    }
    
    delete to_delete;
}

void DoubleList::delete_index(int index)
{
    Node *curr = head;
    index = min(index, this->get_length() - 1);
    for (int i = 0; i < index; ++i)
    {
        curr = curr->next;
    }
    delete_node(curr);
}

void DoubleList::delete_num(int num)
{
    int index = find_n(num);
    if (index == -1)
    {
        cout << "There's no node whose number is " << num << endl;
        return;
    }
    delete_index(index);
}

DoubleList DoubleList::reverse() const
{
    // 初始节点为队头
    Node *curr = head;
    while (curr->next)
    {
        Node *cache = curr->next;
        curr->next = curr->prev;
        curr = cache;
    }
    // 现在节点到了队尾
    curr->next = curr->prev;
    curr->prev = nullptr;
    
    // 头节点变为队尾的节点
    Node *new_head = curr;
    
    // 重新倒回第一个节点
    while (curr->next)
    {
        Node *cache = curr->next;
        cache->prev = curr;
        curr = cache;
    }
    
    return DoubleList(new_head);
}

DoubleList DoubleList::sort() const
{
    int length = get_length();
    for (int i = 0; i < length; ++i)
    {
        for (int j = i + 1; j < length; ++j)
        {
            Node *node1 = find_kth(i);
            Node *node2 = find_kth(j);
            if (node1->data > node2->data)
            {
                int cache = node2->data;
                node2->data = node1->data;
                node1->data = cache;
            }
        }
    }
    Node *new_head = find_kth(0);
    return DoubleList(new_head);
}

int main(int argc, char* argv[])
{
    int len, index, num;
    
    cout << "Initialize the length of the double list :" << endl;
    cin >> len;
    DoubleList list = DoubleList::create(len);
    list = list.sort();
    cout << "Sorted double list is :" << endl;
    list.print();
    cout << endl;
    
    cout << "The doubly linked list before insertion is:" << endl;
    list.print();
    cout << "Please enter the index of the node to be inserted after this one:" << endl;
    cin >> index;
    list.insert_after_index(index, )
    
    return 0;
}
