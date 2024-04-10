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
    return;
}

bool pop(LinkedQueue &q, int &data)
{
    // 队空
    if (empty(q))
        return false;

    // 队未空
    data = q.front->next->data;
    LNode *target = q.front->next;
    q.front->next = target->next;
    // ! 判断尾指针是否是最后一个
    // 若原队列只有一个结点，删除后需将rear指向头结点
    if (q.rear == target)
        q.rear = q.front;
    delete target;
    return true;
}