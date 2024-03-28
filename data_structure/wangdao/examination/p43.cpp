#include <cstdio>

typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkedList, *CircularLinkedList;

typedef struct DNode
{
    int data;
    DNode *prior, *next;
} DNode, *DoubleLinkedList, *DoubleCircularLinkedList;

// 1
void del_x_with_head(LinkedList &head, int x)
{
    LNode *currNode = head;
    while (currNode->next != nullptr)
    {
        // 判断下一个结点值是否等于x
        if (currNode->next->data == x)
        {
            // 删除下一个结点
            LNode *delNode = currNode->next;
            currNode->next = delNode->next;
            delete delNode;
        }
        currNode = currNode->next;
    }
    return;
}
// tc=O(n),sc=O(1)

// 2
void del_min_with_head(LinkedList &head)
{
    LNode *currNode = head;
    int minVal = head->next->data;
    LNode *prevDelNode;
    while (currNode->next != nullptr)
    {
        if (currNode->next->data < minVal)
        {
            minVal = currNode->next->data;
            prevDelNode = currNode;
        }
        currNode = currNode->next;
    }
    LNode *delNode = prevDelNode->next;
    prevDelNode->next = delNode->next;
    delete delNode;
    return;
}
// tc=O(n),sc=O(1)

// 3
void reverse_with_head(LinkedList &head)
{
    LNode *tempHead = nullptr;
    while (head->next != nullptr)
    {
        LNode *currNode = head->next;
        head->next = currNode->next;
        currNode->next = tempHead;
        tempHead = currNode;
    }
    head->next = tempHead;
    return;
}
// tc=O(n),sc=O(1)

// 4
void del_range_with_head(LinkedList &head, int min, int max)
{
    LNode *currNode;
    while (currNode->next != nullptr)
    {
        if (currNode->next->data < max && currNode->next->data > min)
        {
            LNode *delNode = currNode->next;
            currNode->next = delNode->next;
            delete delNode;
        }
    }
    return;
}

// 5
// 双指针

// 6
void split(LinkedList &c, LinkedList &a, LinkedList &b, int n)
{
    LNode *curr_a = a, *curr_b = b;
    for (int i = 0; i < n; i++)
    {
        curr_a->next = c->next;
        curr_a = curr_a->next;
        c->next = curr_a->next;

        curr_b->next = c->next;
        curr_b = curr_b->next;
        c->next = curr_b->next;
    }
    return;
}

// 7
void del_same(LinkedList &head)
{
    LNode *currNode = head;
    while (currNode->next != nullptr && currNode->next->data == currNode->data)
    {
        while (currNode->next->data == currNode->data)
        {
            LNode *delNode = currNode->next;
            currNode->next = delNode->next;
            delete delNode;
        }
        currNode = currNode->next;
    }
    return;
}

// 8
void same(LinkedList &c, LinkedList &a, LinkedList &b)
{
    LNode *currA = a, *currB = b, *currC = c;
    currC = new LNode;
    while (currA != nullptr && currB != nullptr)
    {
        if (currA->data == currB->data)
        {
            currC->next = new LNode;
            currC = currC->next;
            currC->data = currA->data;
            currA = currA->next;
            currB = currB->next;
        }
        else
        {
            if (currA->data < currB->data)
            {
                currA = currA->next;
            }
            else
            {
                currB = currB->next;
            }
        }
    }
    LNode *delNode = c;
    c = c->next;
    delete delNode;
    return;
}

// 9
// 同上

// 10
bool pattern(LinkedList &a, LinkedList &b)
{
    LNode *currA = a, *currB = b;
    bool is_continuous_subsequence = false;
    while (currA != nullptr)
    {
        if (currA->data == currB->data)
        {
            if (currB->next == nullptr)
            {
                is_continuous_subsequence = true;
                break;
            }
            currB = currB->next;
        }
        else
        {
            currB = b;
        }
        currA = currA->next;
    }
    return is_continuous_subsequence;
}

// 11
bool symmetry(DoubleCircularLinkedList &head)
{
    if (head->next == head)
        return true;

    bool is_symmetrical = true;

    DNode *curr_prior = head->prior, *curr_next = head->next;
    while (curr_next->next != curr_prior || curr_next != curr_prior)
    {
        if (curr_next->data != curr_prior->data)
        {
            is_symmetrical = false;
            break;
        }
    }
    return is_symmetrical;
}

// 12
CircularLinkedList link(CircularLinkedList &h1, CircularLinkedList &h2)
{
    LNode *rear1 = h1, *rear2 = h2;
    while (rear1->next != h1)
    {
        rear1 = rear1->next;
    }
    while (rear2->next != h2)
    {
        rear2 = rear2->next;
    }
    rear1->next = h2;
    rear2->next = h1;
    return h1;
}

// 13
typedef struct LNode13
{
    int data;
    int freq;
    LNode13 *pre, *next;
} *L13;

L13 Locate(L13 &l, int x)
{
    LNode13 *target = l->next;
    while (target != l)
    {
        if (target->data == x)
        {
            break;
        }
    }
    if (target->data == x)
    {
        ++target->freq;
    }
    LNode13 *index = target->pre;
    index->next = target->next;
    index->next->pre = index;
    while (index != l && index->data <= x)
    {
        index = index->pre;
    }
    target->next = index->next;
    target->next->pre = target;
    index->next = target;
    target->pre = index;
    return target;
}

// 14
void circular_right_shift(LinkedList &L, int n, int k)
{
    LNode *fore_head = L, *rear;
    for (int i = 0; i < n - k; i++)
    {
        fore_head = fore_head->next;
    }
    rear = fore_head;
    while (rear->next != nullptr)
    {
        rear = rear->next;
    }
    rear->next = L;
    L = fore_head->next;
    fore_head->next = nullptr;
}

// 15
bool is_cycle(LinkedList &L)
{
    LNode *fast = L, *slow = L;
    while (true)
    {
        for (int i = 0; i < 2; i++)
        {
            fast = fast->next;
            if (fast->next == nullptr)
            {
                return false;
            }

            if (fast == slow)
            {
                return true;
            }
        }
        slow = slow->next;
    }
}

// 16
int max_twins_sum(LinkedList &L, int n)
{
    LNode *currNode = L;
    int *sums = new int[n / 2];
    for (int i = 0; i < n / 2; i++)
    {
        sums[i] = currNode->data;
        currNode = currNode->next;
    }
    for (int i = 0; i < n / 2; i++)
    {
        sums[i] += currNode->data;
        currNode = currNode->next;
    }

    int max = sums[0];
    for (int i = 0; i < n / 2; i++)
    {
        if (sums[i] > max)
        {
            max = sums[i];
        }
    }

    delete sums;
    return max;
}

// 17
int find_k_th_last(LinkedList &l, int k)
{
    LNode *fast = l, *slow = l;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
        if (fast == nullptr && i != k)
        {
            return 0;
        }
    }
    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    printf("%d", slow->data);
    return 1;
}

// 18
