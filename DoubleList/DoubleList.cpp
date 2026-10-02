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
    
    cout << "输入每个节点的数值：" << endl;
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
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int DoubleList::get_length()
{
    
}

int main(int argc, char* argv[])
{
    DoubleList d = DoubleList::create(3);
    d.print();
    return 0;
}
