/* 
 * 堆是一个完全二叉树，除了最下一层其余所有层必须是满的，
 * 节点数为 k, 2^(h - 1) + 1 <= k <= 2^h - 1
 */

#pragma once
#include <iostream>
#include <queue>

using namespace std;

class MaxHeap
{
public:
    int data;
    MaxHeap *left;
    MaxHeap *right;
    
    /// 最大堆构造函数
    /// @param data 
    /// @param left
    /// @param right
    MaxHeap(int data, MaxHeap *left, MaxHeap *right);
    
    
    static MaxHeap* create_max_heap(vector<int> &values);
};
