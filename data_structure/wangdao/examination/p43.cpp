typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkedList;

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
