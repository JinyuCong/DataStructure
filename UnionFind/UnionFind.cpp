#include "UnionFind.h"
using namespace std;

UnionFind::UnionFind(int size)
{
    this->array = new int[size];
    for (int i = 0; i < size; ++i)
    {
        array[i] = -1;
    }
    this->count = size;
}

int UnionFind::find(int x)
{
    if (array[x] == -1)
    {
        return x;
    }
    int root = find(array[x]);
    array[x] = root;
    return root;
}

void UnionFind::_union(int a, int b)
{
    // 分别找两个节点的根
    int r1 = find(a);
    int r2 = find(b);
    // 如果两个根相等说明这两个节点在同一个集合，不用再找了
    if (r1 == r2)
    {
        return;
    }
    int big = max(r1, r2);
    int small = min(r1, r2);
    array[big] += array[small];
    array[small] = big;
    count--;
}

bool UnionFind::check(int a, int b)
{
    int r1 = find(a);
    int r2 = find(b);
    return r1 == r2;
}

int UnionFind::get_count() const
{
    return count;
}

int main(int argc, char* argv[])
{
    int size;
    cin >> size;
    UnionFind uf = UnionFind(size);
    
    while(true)
    {
        char ch;
        cin >> ch;
        if(ch == 'S')
        {
            break;
        }
        int root1, root2;
        cin >> root1 >> root2;
        switch(ch)
        {
            case 'I':
                uf._union(root1,root2);
                break;
            case 'C':
                if(uf.check(root1,root2)){
                    cout<<"yes"<<endl;
                } else
                {
                    cout<<"no"<<endl;
                }
                break;
        }
    }
    int count = uf.get_count();
    if(count > 1)
    {
        cout<<"There are "<<count<<" components.";
    } else
    {
        cout<<"The network is connected."; 
    }
	
    return 0;
}
