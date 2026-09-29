#include "BinaryTree.h"
#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;


BinaryTree::BinaryTree(
    char data = NULL, 
    BinaryTree* left = nullptr, 
    BinaryTree* right = nullptr)
{
    this->data = data;
    this->left = left;
    this->right = right;
}


BinaryTree* BinaryTree::create_binary_tree(vector<char> &values)
{
    BinaryTree *ptr;
    char ch = values[0];
    
    if (ch == '#')
    {
        ptr = nullptr;
        values.erase(values.begin());
    }
    else
    {
        ptr = new BinaryTree();
        ptr->data = ch;
        values.erase(values.begin());
        ptr->left = create_binary_tree(values);
        ptr->right = create_binary_tree(values);
    }
    
    return ptr;
}

void BinaryTree::preorder_traversal(BinaryTree *root)
{
    if (!root)
    {
        return;
    }
    std::cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void BinaryTree::preorder_traversal2(BinaryTree* root)
{
    stack<BinaryTree*> stack;
    BinaryTree *curr = root;

    while (curr || !stack.empty())
    {
        while (curr)
        {
            cout << curr->data << " ";
            stack.push(curr);
            curr = curr->left;
        }
        curr = stack.top();
        stack.pop();
        curr = curr->right;
    }
}

void BinaryTree::inorder_traversal(BinaryTree* root)
{
    if (!root)
    {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void BinaryTree::inorder_traversal2(BinaryTree* root)
{
    stack<BinaryTree*> stack;
    BinaryTree *curr = root;

    while (curr || !stack.empty())
    {
        while (curr)  // 一路遍历到最左边的节点入栈
        {
            stack.push(curr);
            curr = curr->left;
        }
        curr = stack.top();  // 从最左边的节点开始出栈
        stack.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void BinaryTree::postorder_traversal(BinaryTree* root)
{
    if (!root)
    {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

void BinaryTree::postorder_traversal2(BinaryTree* root)
{
    stack<BinaryTree*> stack;
    BinaryTree *curr = root;
    stack.push(curr);
    BinaryTree *pre = nullptr;

    while (!stack.empty())
    {
        curr = stack.top();
        if ((!curr->left && !curr->right) || 
            (pre != NULL && (pre == curr->left || pre == curr->right)))
        {
            cout << curr->data << " ";
            stack.pop();
            pre = curr;
        }
        else
        {
            stack.push(curr->right);
            stack.push(curr->left);
        }
    }
}

void BinaryTree::level_order_traversal(BinaryTree* root)
{
    if (!root)
    {
        return;
    }
    
    queue<BinaryTree*> queue;
    queue.push(root);

    while (!queue.empty())
    {
        BinaryTree *curr = queue.front();
        cout << curr->data << " ";
        queue.pop();
        if (curr->left != nullptr)
        {
            queue.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            queue.push(curr->right);
        }
    }
}

int BinaryTree::get_binary_tree_height(BinaryTree *root)
{
    if (!root)
    {
        return 0;
    }
    int left_height = get_binary_tree_height(root->left);
    int right_height = get_binary_tree_height(root->right);
    int height = max(left_height, right_height);
    height += 1;
    return height;
}

bool BinaryTree::judge(BinaryTree* root)
{
    queue<BinaryTree*> queue;
    queue.push(root);

    while (!queue.empty())
    {
        BinaryTree *curr = queue.front();
        queue.pop();
        if (curr != nullptr)
        {
            queue.push(curr->left);
            queue.push(curr->right);
        }
        else
        {
            while (!queue.empty())
            {
                curr = queue.front();
                queue.pop();
                if (curr)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool BinaryTree::find_ancestors(BinaryTree* root, BinaryTree *x)
{
    if (!root)
    {
        return false;
    }
    if (root == x)
    {
        return true;
    }

    if (find_ancestors(root->left, x) || find_ancestors(root->right, x))
    {
        cout << root->data << " ";
        return true;
    }
    else
    {
        return false;
    }
}

void BinaryTree::find_ancestors2(BinaryTree* root, BinaryTree* x)
{
    /*非递归（利用非递归后序遍历）：

    关键性质：后序遍历中访问到某个结点时，栈里剩下的正好是它的全部祖先。
    所以按第 4 条的非递归后序模板写，访问（准备输出）结点时判断它是不是 x。如果是，就把栈里 x 以下的所有元素依次弹出并输出，结束。
    注意：用第 4 条那种写法时，访问 x 的那一刻 x 还在栈顶。要先把 x 弹掉再输出剩下的；或者改用"左走到底 + pre"的后序写法。
    ⚠️ 原代码只用了一个 bool flag 来记录"是否访问过右子树"，但这个状态应该是每个结点各有一份。只用一个变量在很多树上会出错，别照搬。*/
}



int main(int argc, char* argv[])
{
    vector<char> a = {'a', 'b', 'd', '#', '#', 'e', '#', '#', 'c', '#', '#'};
    auto tree = BinaryTree::create_binary_tree(a);
    
    BinaryTree *x = tree->right;
    BinaryTree::find_ancestors(tree, x);
    
    return 0;
}
