typedef struct LNode
{
    int data;
    LNode *next;
};
typedef struct LinkedQueue
{
    LNode *front, *rear;
};

// 带头结点
void init(LinkedQueue &q)
{
    q.front = q.rear = new LNode;
    q.front->next = nullptr;
}

bool empty(LinkedQueue &q)
{
    return q.front == q.rear;
}

void push(LinkedQueue &q, int data)
{
    q.rear->next == new LNode;
    q.rear = q.rear->next;
    q.rear->data = data;
    q.rear->next = nullptr;
}

bool pop(LinkedQueue &q, int &data)
{
    if (empty(q))
        return false;
    data = q.front->next->data;
    LNode *delNode = q.front->next;
    q.front->next = delNode->next;
    // ! 判断尾指针是否是最后一个
    if (q.rear == delNode)
        q.rear = q.front;
    delete delNode;
    return true;
}