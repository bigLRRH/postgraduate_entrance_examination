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
        else
        {
            // ! 写在else里，否则会忽略连续的x
            currNode = currNode->next;
        }
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
    while (head->next)
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
        else
        {
            // ! 没写else
            currNode = currNode->next;
        }
    }
    return;
}

// 5
// !! 双指针
// ! 先对齐再双指针

// 6
void split(LinkedList &c, LinkedList &a, LinkedList &b, int n)
{
    LNode *curr_a = a;
    for (int i = 0; i < n; i++)
    {
        curr_a->next = c->next;
        curr_a = curr_a->next;
        c->next = curr_a->next;

        // ! 看清题目 b和a不一样
        LNode *temp = c->next;
        c->next = temp->next;
        temp->next = b;
        b = temp;
    }
    return;
}

// 7
// ! 很难想象当时的精神状态
void del_same(LinkedList &head)
{
    LNode *currNode = head;
    while (currNode->next)
    {
        if (currNode->next->data == currNode->data)
        {
            LNode *delNode = currNode->next;
            currNode->next = delNode->next;
            delete delNode;
        }
        else
        {
            currNode = currNode->next;
        }
    }
    return;
}

// 8
// ! 看清带头结点
void same(LinkedList &c, LinkedList &a, LinkedList &b)
{
    LNode *currA = a->next, *currB = b->next, *currC = c;
    currC = new LNode;
    while (currA != nullptr && currB != nullptr)
    {
        if (currA->data == currB->data)
        {
            currC->next = new LNode;
            currC = currC->next;
            currC->next = nullptr;
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
    return;
}

// 9
// 同上

// 10
// 滑窗法
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
    // ! 注意循环条件
    while (curr_next->next != curr_prior && curr_next != curr_prior)
    {
        if (curr_next->data != curr_prior->data)
        {
            is_symmetrical = false;
            break;
        }
        // ! 没有迭代
        curr_next = curr_next->next;
        curr_prior = curr_prior->prior;
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
    // ! 看清题目，非循环双链表
    // 找到target
    while (target != nullptr)
    {
        if (target->data == x)
        {
            break;
        }
    }
    // 不存在data值为x的结点
    if (target == nullptr)
    {
        return 0;
    }
    // target == x
    ++target->freq;
    // 取出target
    LNode13 *index = target->pre;
    index->next = target->next;
    index->next->pre = index;
    // 找到target的前驱结点
    while (index != l && index->data <= x)
    {
        index = index->pre;
    }
    // 插入target
    target->next = index->next;
    // ! 判断后面是不是null
    if (target->next)
        target->next->pre = target;
    index->next = target;
    target->pre = index;
    return target;
}

// 14
void circular_right_shift(LinkedList &L, int k)
{
    // ! 自己计算链表长度
    int len = 0;
    for (LNode *currNode = L; currNode != nullptr; currNode = currNode->next)
    {
        ++len;
    }

    LNode *fore_head = L, *rear;
    for (int i = 0; i < len - k; i++)
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
// ! 快慢指针
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
// tn=O(n),sn=O(1)

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
// tn=O(n),sn=O(n)
// ! 可以逆置后半段链表，使空间复杂度变为O(1)

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
// ! 尾部对齐
LinkedList find_mutual_suffix(LinkedList &str1, LinkedList &str2)
{
    int len1 = 0, len2 = 0;
    LNode *currNode1 = str1->next, *currNode2 = str2->next;
    while (currNode1 != nullptr)
    {
        currNode1 = currNode1->next;
        ++len1;
    }
    while (currNode2 != nullptr)
    {
        currNode2 = currNode2->next;
        ++len2;
    }

    currNode1 = str1->next;
    currNode2 = str2->next;

    if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
        {
            currNode1 = currNode1->next;
        }
    }
    else
    {
        for (int i = 0; i < len2 - len1; i++)
        {
            currNode2 = currNode2->next;
        }
    }

    while (currNode1 != nullptr && currNode1 != currNode2)
    {
        currNode1 = currNode1->next;
        currNode2 = currNode2->next;
    }

    return currNode1;
}
// tc=O(n),sc=O(1)

// 19
#include <cmath>
typedef struct LNode19
{
    int data;
    LNode19 *link;
} *LinkedList19;
void remove_abs_duplicates(LinkedList19 &l, int n)
{
    // 字典
    bool *is_occurred = new bool[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        is_occurred[i] = false;
    }
    LNode19 *currNode = l;
    while (currNode->link != nullptr)
    {
        if (is_occurred[abs(currNode->link->data)])
        {
            // 删除结点
            LNode19 *delNode = currNode->link;
            currNode->link = delNode->link;
            delete delNode;
        }
        else
        {
            // 跳过并标记
            is_occurred[abs(currNode->link->data)] = true;
            currNode = currNode->link;
        }
    }

    delete is_occurred;

    return;
}
// tc=O(n),sc=O(n)

// 20
// 倒置后半段
typedef struct LNode20
{
    int data;
    LNode20 *next;
} *LinkedList20;
void realign(LinkedList20 &head, int n)
{
    LNode20 *h2 = new LNode20;
    LNode20 *currNode = head;
    for (int i = 0; i < n / 2; i++)
    {
        currNode = currNode->next;
    }
    h2->next = currNode->next;

    // reverse h2
    LNode20 *temp_h2 = nullptr;
    while (h2->next)
    {
        LNode20 *temp = h2->next;
        h2->next = temp->next;
        temp->next = temp_h2;
        temp_h2 = temp;
    }

    // realign
    LNode20 *currNode1 = head->next;
    while (currNode->next)
    {
        LNode20 *temp = h2->next;
        h2->next = temp->next;
        temp->next = currNode->next;
        currNode->next = temp;
        currNode = temp->next;
    }
    if (h2->next)
    {
        currNode->next = h2->next;
    }

    delete h2;
}
// tn=O(n),sn=O(1)