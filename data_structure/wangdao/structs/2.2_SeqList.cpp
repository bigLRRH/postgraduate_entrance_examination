#define ElemType int
#define MaxSize 50
typedef struct SeqList
{
    ElemType data[MaxSize];
    int length;
};

#define InitSize 100
typedef struct DynamicSeqList
{
    ElemType *data;
    int size, length;
};

// 初始化
void initSeqList(SeqList &L)
{
    L.length = 0;
}

void initDynamicSeqList(DynamicSeqList &L)
{
    L.data = new int[InitSize];
    L.size = InitSize;
    L.length = 0;
}

// 插入
bool insert(SeqList &L, int i, ElemType e)
{
    if (i < 1 && i > L.length + 1)
    {
        return false;
    }
    if (L.length >= MaxSize)
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 删除
bool erase(SeqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
    {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return false;
}

// 查找
int locateElem(SeqList &L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}