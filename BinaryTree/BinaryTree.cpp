#include "BinaryTree.h"
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <regex>
#include <tuple>
#include <valarray>

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
    stack.push(root);

    while (!stack.empty())
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

int BinaryTree::get_binary_tree_height2(BinaryTree* root)
{
    if (!root)
    {
        return 0;
    }
    queue<tuple<BinaryTree*, int>> queue;
    queue.push(make_tuple(root, 1));
    int depth = 0;
    while (!queue.empty())
    {
        auto queue_head = queue.front();
        queue.pop();
        auto queue_head_node = get<0>(queue_head);
        auto queue_head_level = get<1>(queue_head);
        depth = max(queue_head_level, depth);
        if (queue_head_node->left != nullptr)
        {
            queue.push(make_tuple(queue_head_node->left, queue_head_level + 1));
        }
        if (queue_head_node->left != nullptr)
        {
            queue.push(make_tuple(queue_head_node->left, queue_head_level + 1));
        }
    }
    return depth;
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
    stack<BinaryTree*> stack;
    BinaryTree *curr = root;
    stack.push(curr);
    BinaryTree *pre = nullptr;
    
    while (!stack.empty())
    {
        curr  = stack.top();
        
        if (curr == x)
        {
            stack.pop();
            while (!stack.empty())
            {
                cout << stack.top()->data << " ";
                stack.pop();
            }
            return;
        }
        
        if ((!curr->left && !curr->right) || 
            (pre != NULL && (pre == curr->left || pre == curr->right)))
        {
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

int BinaryTree::get_width(BinaryTree* root)
{
    int max_size = 0;
    
    if (!root)
    {
        return 0;
    }
    
    queue<BinaryTree*> queue;
    queue.push(root);
    while (!queue.empty())
    {
        int size = (int)queue.size();
        max_size = max(max_size, size);
        
        BinaryTree *curr = queue.front();
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
    return max_size;
}

int BinaryTree::WPL(BinaryTree* root)
{
    queue<tuple<BinaryTree*, int>> queue;
    auto root_level = make_tuple(root, 0);
    queue.push(root_level);
    
    int sum = 0;
    
    while (!queue.empty())
    {
        BinaryTree *curr = get<0>(queue.front());
        int curr_level = get<1>(queue.front());
        queue.pop();
        if (!curr->left && !curr->right)
        {
            int weight = curr->data - '0';
            sum += weight * curr_level;
        }
        
        if (curr->left)
        {
            auto left_level = make_tuple(curr->left, curr_level + 1);
            queue.push(left_level);
        }
        if (curr->right)
        {
            auto right_level = make_tuple(curr->right, curr_level + 1);
            queue.push(right_level);
        }
    }
    
    return sum;
}

BinaryTree* BinaryTree::pre_in_build(vector<char> &preorder, vector<char> &inorder)
{
    /// 先序序列的第一个元素永远是当前树的根节点，利用该根节点去中序序列中定位，
    /// 就能把中序序列划分为左子树和右子树
    if (preorder.empty() && inorder.empty())
    {
        return nullptr;
    }
    
    BinaryTree *root = new BinaryTree(preorder[0], nullptr, nullptr);
    int root_index;
    for (int i = 0; i < static_cast<int>(inorder.size()); ++i)
    {
        if (inorder[i] == root->data)
        {
            root_index = i;
        }
    }
    
    vector<char> left_tree_data(inorder.begin(), inorder.begin() + root_index);
    vector<char> right_tree_data(inorder.begin() + root_index + 1, inorder.end());
    
    return root;
    
}

bool BinaryTree::print_path(BinaryTree* node, const char target, stack<BinaryTree*> path)
{
    if (!node)
    {
        return false;
    }
    
    path.push(node);
    if (path.top()->data == target)
    {
        while (!path.empty())
        {
            if (path.size() == 1)
            {
                cout << path.top()->data;
                path.pop();
                return true;
            }
            cout << path.top()->data << " <- ";
            path.pop();
        }
    }
    
    bool found = false;
    if (!found && node->left != nullptr)
    {
        found = print_path(node->left, target, path);
    }
    if (!found && node->right != nullptr)
    {
        found = print_path(node->right, target, path);
    }
    return found;
}

int main(int argc, char* argv[])
{
    // vector<char> preorder = {'a', 'b', 'd', 'e', 'c'};
    // vector<char> inorder = {'d', 'b', 'e', 'a', 'c'};
    //
    // BinaryTree::pre_in_build(preorder, inorder);
    vector<char> a = {'a', 'b', 'd', '#', '#', 'e', '#', '#', 'c', '#', '#'};
    auto tree = BinaryTree::create_binary_tree(a);
    
    cout << "前序遍历（递归）：" << endl;
    BinaryTree::preorder_traversal(tree);
    cout << endl;
    cout << "前序遍历（非递归）：" << endl;
    BinaryTree::preorder_traversal2(tree);
    cout << endl; 
    return 0;
}
