#define MAXSIZE 50
// 循环队列
typedef struct
{
    int base[MAXSIZE];
    int front, rear;
} SeqQueue;

void init(SeqQueue &q)
{
    q.rear = q.front = 0;
}

bool empty(SeqQueue &q)
{
    return q.rear == q.front;
}

bool push(SeqQueue &q, int data)
{
    if ((q.rear + 1) % MAXSIZE == q.front)
        return false;
    q.base[q.rear] = data;
    q.rear = (q.rear + 1) % MAXSIZE;
    return true;
}

bool pop(SeqQueue &q, int &data)
{
    if (q.rear == q.front)
        return false;
    data = q.base[q.front];
    q.front = (q.front + 1) % MAXSIZE;
    return true;
}

