typedef struct LNode
{
    int data;
    LNode *next;
} LinkedStack;
void init(LinkedStack &s)
{
    s.next = nullptr;
}
void push(LinkedStack &s, const int &data)
{
    LNode *newNode = new LNode;
    newNode->data = data;
    newNode->next = s.next;
    s.next = newNode;
    return;
}

bool pop(LinkedStack &s, int &data)
{
    if (s.next == nullptr)
    {
        return false;
    }
    LNode *target = s.next;
    data = target->data;
    s.next = target->next;
    delete target;
    return true;
}