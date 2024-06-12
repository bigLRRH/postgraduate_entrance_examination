#define MAXSTRLEN 255
typedef char SString[MAXSTRLEN + 1]; // SString[0] is length

// 4.2.1 brute force
// Str = string
int index(SString mainStr, SString subStr)
{
    int i = 1, j = 1;
    while (i <= mainStr[0] && j <= subStr[0])
    {
        if (mainStr[i] == subStr[j])
        {
            // continue to compare subsequent characters
            ++i;
            ++j;
        }
        else
        {
            // move the pointers back and starts matching again
            i = i - j + 2;
            j = 0;
        }
    }
    if (j > subStr[0])
        return i - subStr[0];
    return 0;
}
// n = mainStr.length()
// m = subStr.length()
// tn=O(m*n)

// 4.2.2 kmp
void get_next(SString subStr, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < subStr[0])
    {
        if (j == 0 || subStr[i] == subStr[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
// m = subStr.length()
// tn=o(m)

// 4.2.3 better kmp
void get_nextVal(SString subStr, int nextVal[])
{
    int i = 1, j = 0;
    nextVal[1] = 0;
    while (i < subStr[0])
    {
        if (j == 0 || subStr[i] == subStr[j])
        {
            ++i;
            ++j;
            if (subStr[i] != subStr[j])
            {
                nextVal[i] = j;
            }
            else
                nextVal[i] = nextVal[j];
        }
        else
            j = nextVal[j];
    }
}