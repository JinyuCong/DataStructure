#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class BinaryTree
{
public:
    char data;
    BinaryTree *left;
    BinaryTree *right;
    
    BinaryTree(char data, BinaryTree *left, BinaryTree *right);
    
    /// 创建二叉树
    static BinaryTree *create_binary_tree(vector<char> &values);
    
    /// 递归前序遍历 
    /// @param root 根节点
    static void preorder_traversal(BinaryTree *root);

    /// 非递归前序遍历 
    /// @param root 根节点
    static void preorder_traversal2(BinaryTree *root);

    /// 递归中序遍历
    /// @param root 根节点
    static void inorder_traversal(BinaryTree *root);

    /// 非递归中序遍历
    /// @param root 根节点
    static void inorder_traversal2(BinaryTree *root);

    /// 递归后序遍历
    /// @param root 根节点
    static void postorder_traversal(BinaryTree *root);
    
    
    /// 非递归后序遍历
    /// @param root 根节点
    static void postorder_traversal2(BinaryTree *root);

    /// 层次遍历
    /// @param root 根节点
    static void level_order_traversal(BinaryTree *root);
    
    /// 递归求二叉树高度
    /// @param root 根节点
    /// @return (int) 高度
    static int get_binary_tree_height(BinaryTree *root);

    /// 非递归求二叉树高度
    /// @param root 根节点
    /// @return (int) 高度
    static int get_binary_tree_height2(BinaryTree *root);

    /// 判断是不是完全二叉树
    /// @param root 根节点
    /// @return (bool) 是否为完全二叉树
    static bool judge(BinaryTree *root);

    /// 递归打印x结点的祖先结点 
    /// @param root 根节点
    /// @param x 树的某个节点
    /// @return 
    static bool find_ancestors(BinaryTree* root, BinaryTree *x);

    /// 非递归打印x结点的祖先结点
    /// @param root 根节点
    /// @param x 树的某个节点
    static void find_ancestors2(BinaryTree* root, BinaryTree *x);

    /// 求二叉树的宽度
    /// @param root 根节点
    /// @return (int) 二叉树宽度
    static int get_width(BinaryTree *root);

    /// 求叶子节点带权路径长度之和
    /// @param root 根节点
    /// @return (int) 叶子节点带权路径长度之和
    static int WPL(BinaryTree *root);

    /// 
    /// @param preorder
    /// @param inorder
    /// @return 
    static BinaryTree* pre_in_build(vector<char> &preorder, vector<char> &inorder);
    
    /// 打印二叉树到目标节点的路径
    /// @param node dfs节点
    /// @param target 目标节点值
    /// @param path 需要维护的路径
    /// @return 是否找到了这个节点target
    static bool print_path(BinaryTree *node, char target, stack<BinaryTree*> path);
};