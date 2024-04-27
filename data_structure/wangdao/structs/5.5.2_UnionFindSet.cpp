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
void merge(int s[], int i, int j)
{
    if (i == j)
        return;
    s[j] = i;
}

// 优化
int fix(int s[], int x)
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

void mix(int s[], int i, int j)
{
    if (i == j)
    {
        return;
    }
    // ! 负数值大的是小树
    if (s[j] > s[i])
    {
        s[i] += s[j];
        s[j] = i;
    }
    else
    {
        s[j] += s[i];
        s[i] = j;
    }
}