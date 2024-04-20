#define SIZE 100
int UnionFindSet[SIZE];

void initial(int s[])
{
    for (int i = 0; i < SIZE; ++i)
    {
        s[i] = -1;
    }
}

// 找到x的根
int find(int s[], int x)
{
    while (s[x] > 0)
    {
        x = s[x];
    }
    return x;
}

// union是内置符
void Union(int s[], int root1, int root2)
{
    if (root1 == root2)
        return;
    s[root2] = root1;
}

// 优化
void advancedUnion(int s[], int root1, int root2)
{
    if (root1 == root2)
    {
        return;
    }
    // ! 负数值大的是小树
    if (s[root2] > s[root1])
    {
        s[root1] += s[root2];
        s[root2] = root1;
    }
    else
    {
        s[root2] += s[root1];
        s[root1] = root2;
    }
}

int advancedFind(int s[], int x)
{
    int root = x;
    while (s[root] >= 0)
    {
        root = s[root];
    }
    while (x != root)
    {
        int t = s[x];
        s[x] = root;
        x = t;
    }
    return root;
}