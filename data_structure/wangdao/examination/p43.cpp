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
