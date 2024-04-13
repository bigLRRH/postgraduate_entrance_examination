// 1
struct queue1
{
    int base[10];
    int front, rear;
    int tag;
};

bool isFull_queue1(queue1 &q)
{
    return q.front == q.rear && q.tag == 1;
}

bool isEmpty_queue1(queue1 &q)
{
    return q.front == q.rear && q.tag == 0;
}

bool push_queue1(queue1 &q, int data)
{
    // queue is full
    if (isFull_queue1(q))
    {
        return false;
    }

    // queue is not full
    q.base[q.rear] = data;
    q.rear = (q.rear + 1) % 11;
    q.tag = 1;
    return true;
}

bool pop_queue1(queue1 &q, int &data)
{
    // queue is empty
    if (isEmpty_queue1(q))
    {
        return false;
    }

    // queue is not empty
    data = q.base[q.front];
    q.front = (q.front + 1) % 11;
    q.tag = 0;
    return true;
}

// 2
typedef struct LNode2
{
    int data;
    LNode2 *next;
} stack2;
typedef struct queue2
{
    LNode2 *front, *rear;
};
void init_queue2(queue2 &q)
{
    q.front = q.rear = new LNode2;
    q.front->next = nullptr;
}
bool isEmpty_queue2(queue2 &q)
{
    return q.front == q.rear;
}
void push_queue2(queue2 &q, const int &data)
{
    q.rear->next = new LNode2;
    q.rear = q.rear->next;
    q.rear->data = data;
    q.rear->next = nullptr;
    return;
}
bool pop_queue2(queue2 &q, int &data)
{
    // queue is empty
    if (q.front == q.rear)
    {
        return false;
    }

    // queue is not empty
    LNode2 *target = q.front->next;
    data = target->data;
    q.front->next = target->next;
    // 若原队列只有一个结点，就删除target后需将rear指向头结点
    //
    if (target == q.rear)
    {
        q.rear = q.front;
    }
    delete target;
    return true;
}
void init_stack2(stack2 &s)
{
    s.next = nullptr;
}
bool isEmpty_stack2(stack2 &s)
{
    return s.next == nullptr;
}
void push_stack2(stack2 &s, const int &data)
{
    LNode2 *newNode = new LNode2;
    newNode->data = data;
    newNode->next = s.next;
    s.next = newNode;
    return;
}
bool pop_stack2(stack2 &s, int &data)
{
    // 栈空
    if (isEmpty_stack2(s))
    {
        return false;
    }

    // 栈未空
    LNode2 *target = s.next;
    data = target->data;
    s.next = target->next;
    delete target;
    return true;
}
void reverse(queue2 &q)
{
    int temp;
    stack2 s;
    // ! not intuitive
    // while (pop_queue2(q, temp))
    // {
    //     push_stack2(s, temp);
    // }
    // while (pop_stack2(s, temp))
    // {
    //     push_queue2(q, temp);
    // }
    while (!isEmpty_queue2(q))
    {
        pop_queue2(q, temp);
        push_stack2(s, temp);
    }
    while (!isEmpty_stack2(s))
    {
        pop_stack2(s, temp);
        push_queue2(q, temp);
    }
}

// 3
typedef struct LNode3
{
    int data;
    LNode3 *next;
};
typedef struct stack3
{
    int base[10];
    int top;
};

typedef struct queue3
{
    stack3 s1, s2;
};
void init_stack3(stack3 &s)
{
    s.top = -1;
}
bool isEmpty_stack3(stack3 &s)
{
    return s.top == -1;
}
bool isFull_stack3(stack3 &s)
{
    return s.top == 9;
}
bool push_stack3(stack3 &s, const int &x)
{
    if (isFull_stack3(s))
    {
        return false;
    }

    s.base[++s.top] = x;
}
bool pop_stack3(stack3 &s, int &x)
{
    if (isEmpty_stack3(s))
    {
        return false;
    }

    x = s.base[s.top--];
}
bool push_queue3(queue3 &q, int x)
{
    if (isFull_stack3(q.s1))
    {
        if (isEmpty_stack3(q.s2))
        {
            int temp;
            // 需保证s1和s2 size相同
            while (!isEmpty_stack3(q.s1))
            {
                pop_stack3(q.s2, temp);
                push_stack3(q.s1, temp);
            }
        }
        else
        {
            return false;
        }
    }

    push_stack3(q.s1, x);
    return true;
}

// 4
typedef struct LNode4
{
    int data;
    LNode4 *next;
};
typedef struct queue4
{
    LNode4 *front, *rear;
};
void init_queue4(queue4 &q)
{
    q.front = new LNode4;
    q.rear = new LNode4;
    q.front->next = q.rear;
    q.rear->next = new LNode4;
    q.rear->next->next = q.front->next;
}
bool isFull_queue4(queue4 &q)
{
    return q.rear->next = q.front->next;
}
bool isEmpty_queue4(queue4 &q)
{
    return q.front->next = q.rear;
}
void push_queue4(queue4 &q, int data)
{
    if (isFull_queue4(q))
    { // 队满
        q.rear->next = new LNode4;
        q.rear->next->next = q.front->next;
    }
    q.rear = q.rear->next;
    q.rear->data = data;
}
bool pop_queue4(queue4 &q, int &data)
{
    // 队空
    if (isEmpty_queue4(q))
    {
        return false;
    }

    // 队未空
    data = q.front->next->data;
    q.front->next = q.front->next->next;
    return true;
}