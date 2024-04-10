#include <iostream>
#include <string>
using namespace std;
void get_nextval(string T, int nextval[])
{
    int i = 0, j = -1;
    nextval[0] = -1;
    while (i < T.length())
    {
        if (j == -1 || T[i] == T[j])
        {
            ++i;
            ++j;
            if (T[i] != T[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
        else
            j = nextval[j];
    }
}