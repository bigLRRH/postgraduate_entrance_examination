#include <cstddef>
#define ElemType int
typedef struct LNode
{
    ElemType data;
    static LNode *next;
} LNode, *LinkedList;

// 初始化
bool initListWithHead(LinkedList &L)
{
    L = new LNode;
    L->next = NULL;
    return true;
}

bool initList(LinkedList &L)
{
    L = NULL;
    return true;
}

// 求表长
int length(LinkedList &L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 按序号查找结点
LNode *getElem(LinkedList &L, int i)
{
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找结点
LNode *locateElem(LinkedList &L, ElemType &e)
{
    LNode *p = L;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// 插入结点操作
bool ListInsert(LinkedList &L, int i, ElemType e)
{
    LNode *p = L;
    int j=0;
    
}