typedef struct ChildSiblingTreeNode
{
    int data;
    ChildSiblingTreeNode *child, *sibling;
} *ChildSiblingTree;

// 4
int count_leafNodes(ChildSiblingTree T)
{
    if (T)
    {
        int sub_sum = count_leafNodes(T->child) + count_leafNodes(T->sibling);
        if (T->child)
            return sub_sum + 1;
        else
            return sub_sum;
    }
    else
        return 0;
}

// 5
// int max(int a, int b, int c)
// {
//     int max = a;
//     if (b > max)
//         max = b;
//     if (c > max)
//         max = c;
//     return max;
// }
// int depth(ChildSiblingTree T, int d = 1)
// {
//     if (T)
//     {
//         return max(d, depth(T->child, d + 1), depth(T->sibling, d));
//     }
//     else
//         return 0;
// }

int height(ChildSiblingTree T)
{
    if (T)
    {
        int a = height(T->child) + 1;
        int b = height(T->sibling);
        return a > b ? a : b;
    }
    else
        return 0;
}