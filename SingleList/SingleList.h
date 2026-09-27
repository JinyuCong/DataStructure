#pragma once

struct Node
{
public:
    int data;
    Node *next;
    
    Node(int data);
};


class SingleList
{
private:
    Node *head;
    
public:
    /// 单链表构造函数
    /// @param head 链表头节点 
    SingleList(Node *head);
    
    static SingleList create(int len);

    /// 返回链表长度
    /// @return 链表长度
    int get_length() const;
    
    /// 判断单链表是否为空
    bool is_empty() const;
    
    /// 打印单链表
    void print() const;

    /// 在第index个结点后面插入数值为data的结点
    /// @param index 节点角标
    /// @param data 节点数值
    void insert(int index, int data);

    /// 寻找第k个结点,只适用链表不为空的情况 
    /// @param k 角标k
    /// @return 第k个节点
    Node* find_kth(int k) const;

    /// 找到第一个数值为N的节点
    /// @param n 节点的数值
    /// @return 节点index
    int find_n(int n);

    /// 删除链表中第k个节点
    /// @param k 角标k
    void delete_kth(int k);
    
    /// 删除数值为n的节点
    /// @param n 
    void delete_n(int n);

    /// 反转链表
    SingleList reverse() const;

    /// 对两个升序链表进行升序合并
    /// @param list1 第一个链表
    /// @param list2 第二个链表
    /// @return 合并后的链表
    static SingleList merge(SingleList list1, SingleList list2);

    /// 冒泡排序
    /// @return 排序过的链表
    SingleList sort();
};


