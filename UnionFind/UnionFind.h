#pragma once

#include <iostream>

class UnionFind
{
private:
    int *array;
    int count;
    
public:
    /// 并查集构造函数
    /// @param size 并查集大小
    UnionFind(int size);

    /// 找到x所在集合的根，同时把路上经过的结点都直接挂到根下面
    /// @param x 需要找的index
    /// @return x对应的根的值
    int find(int x);

    /// 合并 a、b 所在的两个集合，让小集合挂到大集合下面，避免树越来越高。
    /// @param a 第一个节点
    /// @param b 第二个节点
    void _union(int a, int b);

    /// 判断是否属于同一集合
    /// @param a 
    /// @param b 
    /// @return 
    bool check(int a, int b);

    /// 直接返回 count
    /// @return 
    int get_count() const;
};
