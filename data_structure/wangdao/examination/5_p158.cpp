#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *leftChild, *rightChild;
} *BinaryTree;
void visit(BinaryTreeNode *currNode);

// 3
// ! 非递归
// void postOrder_03(BinaryTreeNode *currNode)
// {
//     if (currNode)
//     {
//         postOrder_03(currNode->leftChild);
//         postOrder_03(currNode->rightChild);
//         visit(currNode);
//     }
// }
void postOrder_nonRecur_03(BinaryTree T)
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

// 4
void levelOrder_reverse(BinaryTree T)
{
    queue<BinaryTreeNode *> q;
    stack<BinaryTreeNode *> s;
    if (T)
        q.push(T);
    while (!q.empty())
    {
        BinaryTreeNode *currNode = q.front();
        s.push(currNode);
        q.pop();
        if (currNode->leftChild)
        {
            q.push(currNode->leftChild);
        }
        if (currNode->rightChild)
        {
            q.push(currNode->rightChild);
        }
    }
    while (!s.empty())
    {
        visit(s.top());
        s.pop();
    }
}

// 5
int getHeight_nonRecur(BinaryTree T)
{
    int max_height{0}, height{0};
    stack<BinaryTreeNode *> s;
    BinaryTreeNode *currNode = T, *preNode;
    while (currNode || !s.empty())
    {
        if (currNode)
        {
            s.push(currNode);
            currNode = currNode->leftChild;
            ++height;
            if (height > max_height)
            {
                max_height = height;
            }
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
                --height;
                preNode = currNode;
                currNode = nullptr;
            }
        }
    }
}

int getHeight_nonRecur2(BinaryTree T)
{
    if (!T)
        return 0;
    queue<BinaryTreeNode *> q;
    BinaryTreeNode *currNode;
    int front{-1}, rear{-1}, last{0}, level{0};
    q.push(T);
    while (!q.empty())
    {
        BinaryTreeNode *currNode = q.front();
        ++front;
        if (currNode->leftChild)
        {
            q.push(currNode->leftChild);
            ++rear;
        }
        if (currNode->rightChild)
        {
            q.push(currNode->rightChild);
            ++rear;
        }
        if (front == last)
        {
            ++level;
            last = rear;
        }
    }
    return level;
}

// 6
bool isComplete(BinaryTree T)
{
    if (!T)
        return true;
    queue<BinaryTreeNode *> q;
    q.push(T);
    while (!q.empty())
    {
        BinaryTreeNode *currNode = q.front();
        q.pop();
        if (currNode)
        {
            q.push(currNode->leftChild);
            q.push(currNode->rightChild);
        }
        else
        {
            while (!q.empty())
            {
                currNode = q.front();
                q.pop();
                if (currNode)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

// 7
void preOrderCount(BinaryTree T, int &count)
{
    if (T)
    {
        if (T->leftChild && T->rightChild)
        {
            ++count;
        }
        preOrderCount(T->leftChild, count);
        preOrderCount(T->rightChild, count);
    }
}
int countDoubleBranchesNode(BinaryTree T)
{
    int count = 0;
    preOrderCount(T, count);
    return count;
}

// 8
void postOrderSwapChild(BinaryTree T)
{
    if (T)
    {
        postOrderSwapChild(T->leftChild);
        postOrderSwapChild(T->rightChild);
        BinaryTreeNode *temp = T->leftChild;
        T->leftChild = T->rightChild;
        T->rightChild = temp;
    }
}

// 9
void get_the_k_th_preOrder_value(BinaryTree T, int k, int &value)
{
    if (T)
    {
        if (k == 1)
            value = T->data;
        else if (k < 1)
            return;
        else
        {
            get_the_k_th_preOrder_value(T->leftChild, --k, value);
            get_the_k_th_preOrder_value(T->rightChild, --k, value);
        }
    }
}

// 10
void postOrder_delete(BinaryTree T)
{
    if (T)
    {
        postOrder_delete(T->leftChild);
        postOrder_delete(T->rightChild);
        delete T;
    }
}
void preOrder_find_x(BinaryTree T, int x)
{
    if (T)
    {
        if (T->data == x)
        {
            postOrder_delete(T);
        }
        else
        {
            preOrder_find_x(T->leftChild, x);
            preOrder_find_x(T->rightChild, x);
        }
    }
}

// 11
void find_ancestors_of_x()
{
    
}