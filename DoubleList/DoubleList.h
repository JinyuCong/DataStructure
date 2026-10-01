#pragma once

#include <iostream>


class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    
    Node(int data, Node *prev = nullptr, Node *next = nullptr);
};


class DoubleList
{
private:
    Node *head;
public:
    /// 双链表构造函数
    /// @param head 头节点
    DoubleList(Node *head);

    /// 创建长度为n的双链表
    /// @param n 双链表长度
    /// @return 双链表
    DoubleList* create(int n);
};