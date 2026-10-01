#include "DoubleList.h"
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

DoubleList* DoubleList::create(int n)
{
    Node *head;
    int data;
    cout << "输入每个节点的数值：" << endl;
    cin >> data;
    
}

int main(int argc, char* argv[])
{
    
    return 0;
}
