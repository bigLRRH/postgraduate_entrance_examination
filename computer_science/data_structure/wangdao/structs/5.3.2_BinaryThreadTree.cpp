typedef struct BinaryThreadNode
{
    int data;
    BinaryThreadNode *leftChild, *rightChild;
    int leftTag, rightTag;
} BinaryThreadNode, *BinaryThreadTree;

// create an inOrder binary thread tree
void inOrderThreading(BinaryThreadTree currNode, BinaryThreadTree &preNode)
{
    if (currNode)
    {
        inOrderThreading(currNode->leftChild, preNode);
        if (!currNode->leftChild)
        {
            currNode->leftTag = 1;
            currNode->leftChild = preNode;
        }
        if (preNode && !preNode->rightChild)
        {
            preNode->rightTag = 1;
            preNode->rightChild = currNode;
        }
        preNode = currNode;
        inOrderThreading(currNode->rightChild, preNode);
    }
}

void createInOrderThread(BinaryThreadTree t)
{
    BinaryThreadTree preNode = nullptr;
    if (t != nullptr)
    {
        inOrderThreading(t, preNode);
        preNode->rightChild = nullptr;
        preNode->rightTag = 1;
    }
}

// traverse an inOrder binary thread tree
void visit(BinaryThreadNode *node);
BinaryThreadNode *firstNode(BinaryThreadNode *currNode)
{
    while (currNode->leftTag == 0)
    {
        currNode = currNode->leftChild;
    }
    return currNode;
}
BinaryThreadNode *nextNode(BinaryThreadNode *currNode)
{
    if (currNode->rightTag == 0)
    {
        return firstNode(currNode->rightChild);
    }
    return currNode->rightChild;
}
void inOrder(BinaryThreadTree t)
{
    for (BinaryThreadNode *currNode = t; currNode != nullptr; currNode = nextNode(currNode))
    {
        visit(currNode);
    }
}