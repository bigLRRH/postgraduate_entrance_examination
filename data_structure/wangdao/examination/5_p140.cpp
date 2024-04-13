// 6
int find_nearest_ancestor(int i, int j)
{
    while (i != j)
    {
        // ! 不在同一层
        if (i < j)
            i /= 2;
        else
            j /= 2;
    }
    return i;
}