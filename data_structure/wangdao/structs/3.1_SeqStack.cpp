#define MAXSIZE 50
typedef struct
{
    int base[MAXSIZE];
    int top;
} SeqStack;

void init(SeqStack &s)
{
    s.top = -1;
}

bool isEmpty(SeqStack &s)
{
    return s.top == -1;
}

bool push(SeqStack &s, int x)
{
    // 栈满
    if (s.top == MAXSIZE - 1)
        return false;

    s.base[++s.top] = x;
    return true;
}

bool pop(SeqStack &s, int &x)
{
    // 栈空
    if (isEmpty(s))
        return false;

    x = s.base[s.top--];
    return true;
}

bool getTop(SeqStack &s, int &x)
{
    // 栈空
    if (isEmpty(s))
    {
        return false;
    }

    x = s.base[s.top];
    return true;
}
