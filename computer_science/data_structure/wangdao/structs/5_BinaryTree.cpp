#include <stack>
#include <queue>
using namespace std;

typedef struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *leftChild, *rightChild;
} BinaryTreeNode, *BinaryTree;

void visit(BinaryTree T);
void preOrderTraverse(BinaryTree T)
{
    if (T != nullptr)
    {
        visit(T);
        preOrderTraverse(T->leftChild);
        preOrderTraverse(T->rightChild);
    }
}
void inOrderTraverse(BinaryTree T)
{
    if (T != nullptr)
    {
        inOrderTraverse(T->leftChild);
        visit(T);
        inOrderTraverse(T->rightChild);
    }
}
void postOrderTraverse(BinaryTree T)
{
    if (T != nullptr)
    {
        postOrderTraverse(T->leftChild);
        postOrderTraverse(T->rightChild);
        visit(T);
    }
}
void preOrderTraverse2(BinaryTree T)
{
    stack<BinaryTree> s;
    BinaryTree currNode = T;
    while (currNode || !s.empty())
    {
        if (currNode)
        {
            // preOrder
            visit(currNode);
            s.push(currNode->leftChild);
            currNode = currNode->leftChild;
        }
        else
        {
            currNode = s.top();
            s.pop();
            currNode = currNode->rightChild;
        }
    }
}

void inOrderTraverse2(BinaryTree T)
{
    stack<BinaryTree> s;
    BinaryTree currNode = T;
    while (currNode || !s.empty())
    {
        if (currNode)
        {
            s.push(currNode->leftChild);
            currNode = currNode->leftChild;
        }
        else
        {
            currNode = s.top();
            s.pop();
            // inOrder
            visit(currNode);
            currNode = currNode->rightChild;
        }
    }
}

void postOrderTraverse2(BinaryTree T)
{
    stack<BinaryTreeNode *> s;
    BinaryTreeNode *currNode = T;
    BinaryTreeNode *preNode;
    while (currNode || !s.empty())
    {
        if (currNode)
        {
            s.push(currNode);
            currNode = currNode->leftChild;
        }
        else
        {
            currNode = s.top();
            if (currNode->rightChild && currNode->rightChild != preNode)
            {
                currNode = currNode->rightChild;
            }
            else
            {
                s.pop();
                visit(currNode);
                // !
                preNode = currNode;
                currNode = nullptr;
            }
        }
    }
}

void LevelOrderTraverse(BinaryTree T)
{
    queue<BinaryTree> q;
    BinaryTree currNode;
    if (T)
        q.push(T);
    while (!q.empty())
    {
        currNode = q.front();
        q.pop();
        visit(currNode);
        if (currNode->leftChild != nullptr)
            q.push(T->leftChild);
        if (currNode->rightChild != nullptr)
            q.push(T->rightChild);
    }
}