#pragma once
#include <vcruntime.h>

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    
    Node(int data = NULL, Node *prev = nullptr, Node *next = nullptr);
};


class DoubleList
{
public:
    Node *head;
    
    /// 双链表构造函数
    /// @param head 头节点
    DoubleList(Node *head);

    /// 创建长度为n的双链表
    /// @param n 双链表长度
    /// @return 双链表
    static DoubleList create(int n);
    
    /// 打印双链表
    void print() const;

    /// 返回双链表长度
    /// @return 双链表长度
    int get_length();
};