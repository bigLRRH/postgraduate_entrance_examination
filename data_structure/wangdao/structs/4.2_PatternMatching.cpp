#define MAXSTRLEN 255
typedef char SString[MAXSTRLEN + 1];

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

// 4.2.2 kmp
