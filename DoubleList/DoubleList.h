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
    int get_length() const;

    /// 判断双链表是否为空
    /// @return 是否为空
    bool is_empty() const;

    /// 找到双链表第k个节点
    /// @param k index
    /// @return 第k个节点
    Node* find_kth(int k) const;

    /// 寻找数值为N的节点的下标
    /// @param n 节点数值
    /// @return 这个节点的下标
    int find_n(int n) const;

    /// 在prev_node节点之后插入insert_node节点
    /// @param prev_node 在这个结点之后插入
    /// @param insert_node 需要插入的节点
    static void insert_after_node(Node *prev_node, Node *insert_node);

    /// 在第index个节点之后插入insert_node节点
    /// @param index 在这个下标的节点之后插入新节点
    /// @param insert_node 需要插入的节点
    void insert_after_index(int index, Node *insert_node);

    /// 删除一个节点
    /// @param to_delete 需要删除的节点
    void delete_node(Node *to_delete);

    /// 删除下标为index的节点
    /// @param index 要删除的节点的下标
    void delete_index(int index);
    
    /// 删除第一个值为num的节点
    /// @param num 要删除的节点的值
    void delete_num(int num);

    /// 反转双链表
    /// @return 反转后的双链表
    DoubleList reverse() const;

    /// 冒泡排序
    /// @return 排序后双链表 
    DoubleList sort() const;
};