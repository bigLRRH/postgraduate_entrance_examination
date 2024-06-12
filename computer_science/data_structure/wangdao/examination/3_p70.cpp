// 1
// 3个

// 2
// 没有dbace

// 3
// （1）acd
// （2）
#include <string>
using namespace std;
bool judge(string &s)
{
    int count = 0;
    for (char c : s)
    {
        if (c == 'I')
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count < 0)
        {
            return false;
        }
    }
    return true;
}

// 4
// ! 不要把queue当成栈
#include <stack>
typedef struct LNode4
{
    int data;
    LNode4 *next;
} *LinkedList4;

bool symmetry(LinkedList4 &L)
{
    int length = 0;
    LNode4 *currNode = L;
    for (currNode = L; currNode != nullptr; currNode = currNode->next)
    {
        ++length;
    }
    stack<int> q;
    currNode = L;
    for (int i = 0; i < length / 2; i++)
    {
        q.push(currNode->data);
        currNode = currNode->next;
    }
    if (length % 2)
    {
        currNode = currNode->next;
    }
    while (currNode != nullptr)
    {
        if (q.top() != currNode->data)
            return false;
        q.pop();
        currNode = currNode->next;
    }
    return true;
}

// 5
typedef struct SharedStack
{
    // ! a[50] 是0~49
    int a[50];
    int s1_top = -1;
    int s2_top = 50;
} *sStack;

bool s1_push(sStack &s, int data)
{
    if (s->s2_top - s->s1_top == 1)
        return false;
    s->a[++s->s1_top] = data;
    return true;
}

bool s2_push(sStack &s, int data)
{
    if (s->s2_top - s->s1_top == 1)
        return false;
    s->a[--s->s2_top] = data;
    return true;
}

bool s1_pop(sStack &s, int &data)
{
    if (s->s1_top == -1)
        return false;
    data = s->a[s->s1_top--];
    return true;
}

bool s2_pop(sStack &s, int &data)
{
    if (s->s2_top == 50)
        return false;
    data = s->a[s->s2_top++];
    return true;
}