#include <cstddef>
#include <cstdio>
#define ElemType int

// 2.3.1单链表
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

// 插入结点操作(含头结点)
bool ListInsert(LinkedList &L, int i, ElemType e)
{
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除结点操作
bool ListDelete(LinkedList &L, int i, ElemType &e)
{
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    delete q;
    return true;
}

// 头插法建立单链表（带头结点）
LinkedList List_HeadInsert(LinkedList &L)
{
    LNode *s;
    int x;
    L = new LNode;
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

// 尾插法建立单链表
LinkedList List_TailInsert(LinkedList &L)
{
    int x;
    L = new LNode;
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = new LNode;
        s->data = x;
        s->next = NULL;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    return L;
}

// 2.3.2双链表
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkedList;

// 2.3.5静态链表
#define MaxSize 50
typedef struct
{
    ElemType data;
    int next;
} SLinkList[MaxSize];
