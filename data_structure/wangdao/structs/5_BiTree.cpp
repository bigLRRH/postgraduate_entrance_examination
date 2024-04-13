#include <stack>
#include <queue>
using namespace std;

typedef struct BiTNode
{
    int data;
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void visit(BiTree T);
void preOrderTraverse(BiTree T)
{
    if (T != nullptr)
    {
        visit(T);
        preOrderTraverse(T->lchild);
        preOrderTraverse(T->rchild);
    }
}
void inOrderTraverse(BiTree T)
{
    if (T != nullptr)
    {
        inOrderTraverse(T->lchild);
        visit(T);
        inOrderTraverse(T->rchild);
    }
}
void postOrderTraverse(BiTree T)
{
    if (T != nullptr)
    {
        postOrderTraverse(T->lchild);
        postOrderTraverse(T->rchild);
        visit(T);
    }
}
void preOrderTraverse2(BiTree T)
{
    stack<BiTree> s;
    BiTree currNode = T;
    while (currNode || !s.empty())
    {
        if (currNode)
        {
            // preOrder
            visit(currNode);
            s.push(currNode->lchild);
            currNode = currNode->lchild;
        }
        else
        {
            currNode = s.top();
            s.pop();
            currNode = currNode->rchild;
        }
    }
}

void inOrderTraverse2(BiTree T)
{
    stack<BiTree> s;
    BiTree currNode = T;
    while (currNode || !s.empty())
    {
        if (currNode)
        {
            s.push(currNode->lchild);
            currNode = currNode->lchild;
        }
        else
        {
            currNode = s.top();
            s.pop();
            // inOrder
            visit(currNode);
            currNode = currNode->rchild;
        }
    }
}

void postOrderTraverse2(BiTree T)
{
}

void LevelOrderTraverse(BiTree T)
{
    queue<BiTree> q;
    BiTree currNode;
    q.push(T);
    while (!q.empty())
    {
        currNode = q.front();
        q.pop();
        visit(currNode);
        if (currNode->lchild != nullptr)
            q.push(T->lchild);
        if (currNode->rchild != nullptr)
            q.push(T->rchild);
    }
}