#include <iostream>
#include <queue>
#include <stack>
#include <vector>
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
int countNodesWithDoubleChildren(BinaryTree T)
{
    // return T ? T->leftChild && T->rightChild ? countNodesWithDoubleChildren(T->leftChild) + countNodesWithDoubleChildren(T->rightChild) + 1 : countNodesWithDoubleChildren(T->leftChild) + countNodesWithDoubleChildren(T->rightChild) : 0;
    if (T)
    {
        if (T->leftChild && T->rightChild)
        {
            return countNodesWithDoubleChildren(T->leftChild) + countNodesWithDoubleChildren(T->rightChild) + 1;
        }
        else
        {
            return countNodesWithDoubleChildren(T->leftChild) + countNodesWithDoubleChildren(T->rightChild);
        }
    }
    else
        return 0;
}

// ! not elegant
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
int countNodesWithDoubleChildren2(BinaryTree T)
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
queue<BinaryTreeNode *> find_ancestors_of_x(BinaryTree T, int x)
{
    stack<BinaryTreeNode *> s;
    BinaryTreeNode *currNode = T, *preNode = nullptr;

    // q is the required sequence
    queue<BinaryTreeNode *> q;

    while (currNode || !s.empty())
    {
        if (currNode)
        {
            if (currNode->data == x)
                break;
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
                preNode = currNode;
                currNode = nullptr;
            }
        }
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    return q;
}
// tn=O(n),sn=O(n)
// 可以求先序序列和后序序列通过比较得到祖先结点，自己想的比上面的算法效率略低

// 12
void ancestor(BinaryTree root, BinaryTreeNode *p, BinaryTreeNode *q, BinaryTreeNode *r)
{
    vector<BinaryTreeNode *> v1, v2;
    int top1{-1}, top2{-1};
    BinaryTreeNode *currNode{root}, *preNode{nullptr}, *markNode{nullptr};

    // find all ancestors
    while (currNode || top1 > -1)
    {
        if (currNode)
        {
            if (currNode == p || currNode == q)
            {
                if (top2 == -1)
                {
                    while (top2 < top1)
                    {
                        ++top2;
                        v2[top2] = v1[top2];
                    }
                    markNode = currNode;
                }
                else if (currNode != markNode)
                {
                    break;
                }
            }

            v1[++top1] = currNode;
            currNode = currNode->leftChild;
        }
        else
        {
            currNode = v1[top1];
            if (currNode->rightChild && currNode->rightChild != preNode)
            {
                currNode = currNode->rightChild;
            }
            else
            {
                preNode = currNode;
                currNode = nullptr;
                --top1;
            }
        }
    }

    // find the nearest ancestor
    for (int i = top1; i > -1; --i)
    {
        for (int j = top2; j > -1; --j)
        {
            if (v1[top1] == v2[top2])
            {
                r = v1[top1];
                return;
            }
        }
    }
}

// 13
int getWidth(BinaryTree root)
{
    if (!root)
        return 0;
    queue<BinaryTreeNode *> q;
    int front{-1}, rear{-1}, last{0}, maxWidth{0};
    BinaryTreeNode *currNode;
    q.push(root);
    // ! 初始push也要++rear
    ++rear;
    while (!q.empty())
    {
        currNode = q.front();
        q.pop();
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
            int width = rear - last;
            if (width > maxWidth)
                maxWidth = width;

            last = rear;
        }
    }
    return maxWidth;
}
// tn=O(n),sn=O(n)

// 14
void convertPreSeqToPostSeq_of_fullTree(
    vector<BinaryTreeNode *> const &preSeq, vector<BinaryTreeNode *> &postSeq,
    int preLeft, int preRight, int postLeft, int postRight)
{
    if (preRight == preLeft + 1)
    {
        postSeq[postLeft] = preSeq[preLeft];
        postSeq[postRight] = preSeq[preRight];
    }
    else
    {
        int preRoot = preLeft;
        int postRoot = postRight;
        postSeq[postRoot] = preSeq[preRoot];
        int preLL = preLeft + 1;
        int preLR = (preLeft + preRight + 1) / 2;
        int postLL = postLeft;
        int postLR = (postLeft + postRight + 1) / 2;
        convertPreSeqToPostSeq_of_fullTree(preSeq, postSeq, preLL, preLR, postLL, postLR);
        int preRL = preLR + 1;
        int preRR = preRight;
        int postRL = postLR + 1;
        int postRR = postRight - 1;
        convertPreSeqToPostSeq_of_fullTree(preSeq, postSeq, preRL, preRR, postRL, postRR);
    }
}
void convertPreSeqToPostSeq_of_fullTree(vector<BinaryTreeNode *> const &preSeq, vector<BinaryTreeNode *> &postSeq)
{
    convertPreSeqToPostSeq_of_fullTree(preSeq, postSeq, 0, preSeq.size() - 1, 0, postSeq.size() - 1);
}

// 15
void inOrderThreading(BinaryTreeNode *currNode, BinaryTreeNode *&preNode, BinaryTreeNode *&head)
{
    if (currNode)
    {
        inOrderThreading(currNode->leftChild, preNode, head);
        if (!head)
        {
            head = currNode;
        }
        if (preNode && preNode->rightChild)
        {
            preNode->rightChild = currNode;
        }
        preNode = currNode;
        inOrderThreading(currNode->rightChild, preNode, head);
    }
}
void createInOrderThread(BinaryTree T, BinaryTreeNode *&head)
{
    BinaryTreeNode *preNode;
    inOrderThreading(T, preNode, head);
}

// 16
bool preOrderJudgeSimilarity(BinaryTree T1, BinaryTree T2)
{
    if (T1 && T2)
        return preOrderJudgeSimilarity(
                   T1->leftChild, T2->leftChild) &&
               preOrderJudgeSimilarity(
                   T1->rightChild, T2->rightChild);
    else if (!(T1 || T2))
        return true;
    else
        return false;
}

// 17
typedef struct BinaryTreeNode17
{
    int weight;
    BinaryTreeNode17 *leftChild, *rightChild;

} *BinaryTree17;

int WPL(BinaryTree17 T, int depth = 0)
{
    if (T)
    {
        if (!(T->leftChild || T->rightChild))
            return T->weight * depth;
        return WPL(T->leftChild, depth + 1) + WPL(T->rightChild, depth + 1);
    }
    else
        return 0;
}
// ! 方法2
int WPL2(BinaryTree17 T)
{
    if (T)
    {
        if (!(T->leftChild || T->rightChild))
            return 0;
        else
        {
            int w_l = WPL2(T->leftChild);
            int w_r = WPL2(T->rightChild);
            T->weight = T->leftChild ? T->leftChild->weight : 0 + T->rightChild ? T->rightChild->weight
                                                                                : 0;
            return w_l + w_r + T->weight;
        }
    }
    else
        return 0;
}

// 18
typedef struct node18
{
    char data[10];
    struct node18 *left, *right;
} BTree18;
string infixExpression(BTree18 *T)
{
    if (T)
    {
        if (!(T->left || T->right))
            return T->data;
        else
            return "(" + infixExpression(T->left) + T->data + infixExpression(T->right) + ")";
    }
    else
    {
        return nullptr;
    }
}

// 19
typedef struct
{
    int SqBitNode[100];
    int ElemNum;
} SqBiTree;
int left(int index)
{
    return index * 2 + 1;
}
int right(int index)
{
    return index * 2 + 2;
}
bool inOrderJudgeIsBST(SqBiTree T, int index = 0, int &pre)
{
    if (T.SqBitNode[index] == -1)
        return true;
    if (index >= 0 && index < T.ElemNum)
    {
        bool a = inOrderJudgeIsBST(T, left(index), pre);
        pre = index;
        bool flag = pre == -1 || T.SqBitNode[index] >= T.SqBitNode[pre];
        bool b = inOrderJudgeIsBST(T, right(index), pre);
        return a && b && flag;
    }
    else
        return true;
}
bool judgeIsBST(SqBiTree T)
{
    int pre = -1;
    return inOrderJudgeIsBST(T, pre);
}