#include <iostream>
using namespace std;
#define MAXN 10000
struct NODE
{
    int value;
    int lchild, rchild, father, height;
    int sonCount;
    int balance;
    NODE(){
        lchild = -1;
        rchild = -1;
        father = -1;
        balance = 0;
        height = 0;
        sonCount = 0;
    }
};
class AVL
{
public:
    AVL();
    int nHead;
    int nNodeCount;
    NODE tree[MAXN];
    void Insert(int val);
    int Search(int val);
    void Show(int pos);
    int GetMiddle();
    void Init();
private:
    void LLroation(int pos);
    void LRroation(int pos);
    void RRroation(int pos);
    void RLroation(int pos);
    int GetHeight(int pos);
    void UpdataBalance(int pos);
    void UpdataSingleBalance(int pos);
};
void AVL::Init()
{
    nHead = -1;
    nNodeCount = -1;
}
int AVL::GetMiddle()
{
    int k = nNodeCount / 2;
    int p = nHead;
    int x = 0;
    while (p != -1 && x != k)
    {
        if (tree[p].rchild != -1)
        {
            if (tree[tree[p].rchild].sonCount + 1 + x == k)
            {
                return p;
                break;
            }
            else if (tree[tree[p].rchild].sonCount + 1 + x < k)
            {
                x += tree[tree[p].rchild].sonCount + 2;
                p = tree[p].lchild;
            }
            else
            {
                p = tree[p].rchild;
            }
        }
        else
        {
            x++;
            p = tree[p].lchild;
        }
    }
    while (p != -1)
    {
        x = p;
        p = tree[p].rchild;
    }
    return x;
}
int AVL::Search(int val)
{
    int p = nHead;
    while (p != -1)
    {
        if (tree[p].value == val)
        {
            return p;
        }
        else if (val <= tree[p].value)
        {
            p = tree[p].lchild;
        }
        else
        {
            p = tree[p].rchild;
        }
    }
    return -1;
}
void AVL::Insert(int val)
{
    nNodeCount++;
    tree[nNodeCount].value = val;
    tree[nNodeCount].lchild = tree[nNodeCount].rchild = -1;
    tree[nNodeCount].height = 1;
    tree[nNodeCount].balance = 0;
    tree[nNodeCount].sonCount = 0;
    if (nHead == -1)
    {
        nHead = nNodeCount;
        tree[nNodeCount].father = -1;
        return;
    }
    int p = nHead, q = 0;
    while (p != -1)
    {
        q = p;
        if (val <= tree[p].value)
        {
            p = tree[p].lchild;
        }
        else
        {
            p = tree[p].rchild;
        }
    }
    if (val <= tree[q].value)
    {
        tree[q].lchild = nNodeCount;
        tree[nNodeCount].father = q;
    }
    else
    {
        tree[q].rchild = nNodeCount;
        tree[nNodeCount].father = q;
    }
    UpdataBalance(q);
    while (q != -1)
    {
        if (abs(tree[q].balance) > 1)
        {
            if (tree[q].balance == 2)
            {
                if (tree[tree[q].lchild].balance == 1)
                {
                    LLroation(q);
                }
                else
                {
                    LRroation(q);
                }
            }
            else
            {
                if (tree[tree[q].rchild].balance == 1)
                {
                    RLroation(q);
                }
                else
                {
                    RRroation(q);
                }
            }
            break;
        }
        q = tree[q].father;
    }
}
void AVL::UpdataBalance(int pos)
{
    int x, y, z = 0;
    while (pos != -1)
    {
        z = 0;
        if (tree[pos].lchild != -1)
        {
            z += tree[tree[pos].lchild].sonCount + 1;
        }
        if (tree[pos].rchild != -1)
        {
            z += tree[tree[pos].rchild].sonCount + 1;
        }
        tree[pos].sonCount = z;
        x = GetHeight(tree[pos].lchild);
        y = GetHeight(tree[pos].rchild);
        tree[pos].balance = x - y;
        if (x >= y)
        {
            tree[pos].height = x + 1;
        }
        else
        {
            tree[pos].height = y + 1;
        }
        pos = tree[pos].father;
    }
}
void AVL::UpdataSingleBalance(int pos)
{
    int x, y, z;
    z = 0;
    if (tree[pos].lchild != -1)
    {
        z += tree[tree[pos].lchild].sonCount + 1;
    }
    if (tree[pos].rchild != -1)
    {
        z += tree[tree[pos].rchild].sonCount + 1;
    }
    tree[pos].sonCount = z;
    x = GetHeight(tree[pos].lchild);
    y = GetHeight(tree[pos].rchild);
    tree[pos].balance = x - y;
    if (x >= y)
    {
        tree[pos].height = x + 1;
    }
    else
    {
        tree[pos].height = y + 1;
    }
    pos = tree[pos].father;
}
int AVL::GetHeight(int pos)
{
    if (pos == -1)
    {
        return 0;
    }
    else
    {
        return tree[pos].height;
    }
}
void AVL::LLroation(int pos)
{
    int a, b, c;
    a = pos;
    b = tree[pos].lchild;
    tree[b].father = tree[a].father;
    if (tree[b].father != -1)
    {
        c = tree[b].father;
        if (tree[c].lchild == a)
        {
            tree[c].lchild = b;
        }
        else
        {
            tree[c].rchild = b;
        }
    }
    else
    {
        nHead = b;
    }
    tree[a].lchild = tree[b].rchild;
    if (tree[b].rchild != -1)
    {
        c = tree[b].rchild;
        tree[c].father = a;
    }
    tree[b].rchild = a;
    tree[a].father = b;
    UpdataBalance(a);
}
void AVL::RRroation(int pos)
{
    int a, b, c;
    a = pos;
    b = tree[pos].rchild;
    tree[b].father = tree[a].father;
    if (tree[b].father != -1)
    {
        c = tree[b].father;
        if (tree[c].lchild == a)
        {
            tree[c].lchild = b;
        }
        else
        {
            tree[c].rchild = b;
        }
    }
    else
    {
        nHead = b;
    }
    tree[a].rchild = tree[b].lchild;
    if (tree[b].lchild != -1)
    {
        c = tree[b].lchild;
        tree[c].father = a;
    }
    tree[b].lchild = a;
    tree[a].father = b;
    UpdataBalance(a);
}
void AVL::LRroation(int pos)
{
    int a, b, c;
    a = pos;
    b = tree[a].lchild;
    c = tree[b].rchild;
    tree[c].father = tree[a].father;
    if (tree[c].father != -1)
    {
        if (tree[tree[c].father].lchild == a)
        {
            tree[tree[c].father].lchild = c;
        }
        else
        {
            tree[tree[c].father].rchild = c;
        }
    }
    else
    {
        nHead = c;
    }
    tree[b].rchild = tree[c].lchild;
    if (tree[c].lchild != -1)
    {
        tree[tree[c].lchild].father = b;
    }
    tree[a].lchild = tree[c].rchild;
    if (tree[c].rchild != -1)
    {
        tree[tree[c].rchild].father = a;
    }
    tree[c].lchild = b;
    tree[c].rchild = a;
    tree[a].father = c;
    tree[b].father = c;
    UpdataSingleBalance(b);
    UpdataBalance(a);
}
void AVL::RLroation(int pos)
{
    int a, b, c;
    a = pos;
    b = tree[a].rchild;
    c = tree[b].lchild;
    tree[c].father = tree[a].father;
    if (tree[c].father != -1)
    {
        if (tree[tree[c].father].lchild == a)
        {
            tree[tree[c].father].lchild = c;
        }
        else
        {
            tree[tree[c].father].rchild = c;
        }
    }
    else
    {
        nHead = c;
    }
    tree[a].rchild = tree[c].lchild;
    if (tree[a].rchild != -1)
    {
        tree[tree[a].rchild].father = a;
    }
    tree[b].lchild = tree[c].rchild;
    if (tree[b].lchild != -1)
    {
        tree[tree[b].lchild].father = b;
    }
    tree[c].lchild = a;
    tree[c].rchild = b;
    tree[a].father = c;
    tree[b].father = c;
    UpdataSingleBalance(b);
    UpdataBalance(a);
}
void AVL::Show(int pos)
{
    int i;
    for (i = 0; i < tree[pos].height; i++)
    {
        printf("..");
    }
    printf("[%2d]  sonCount=%d\n", tree[pos].value, tree[pos].sonCount);
    if (tree[pos].lchild != -1)
    {
        Show(tree[pos].lchild);
    }
    if (tree[pos].rchild != -1)
    {
        Show(tree[pos].rchild);
    }
}
AVL::AVL()
{
    nHead = -1;
    nNodeCount = -1;
}
int main()
{
    AVL avltree;
    int tc;
    int i, j, n, k;
    scanf("%d", &tc);
    while (tc--)
    {
        avltree.Init();
        scanf("%d %d", &k, &n);
        printf("%d %d\n", k, (n+1)/2);
        j = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &k);
            avltree.Insert(k);
            if (i % 2 == 0)
            {
                k = avltree.GetMiddle();
                if (j < 9 && i != n-1)
                {
                    printf("%d ", avltree.tree[k]);
                    j++;
                }
                else
                {
                    printf("%d\n", avltree.tree[k]);
                    j = 0;
                }
            }
        }
        if (j > 0)
        {
            printf("\n");
        }
    }    
    return 0;
}