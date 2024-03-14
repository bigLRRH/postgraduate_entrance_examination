#define MAXSIZE 100
typedef int ElemType;
typedef struct SeqList
{
    ElemType data[MAXSIZE];
    int length;
};

// 二.综合应用题
// 1
bool del_min(SeqList &L, ElemType &value)
{
    if (L.length == 0)
        return false;
    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < value)
        {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

// 2
void reverse(SeqList &L)
{
    for (int i = 0; i < L.length / 2; i++)
    {
        ElemType temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}

// 3
void del_x(SeqList &L, ElemType x)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k + 1;
}

// 4
void del_s_t(SeqList &L, ElemType s, ElemType t)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] >= s && L.data[i] <= t)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k + 1;
}

// 5
void del_same(SeqList &L)
{
    int k=0;
    
}