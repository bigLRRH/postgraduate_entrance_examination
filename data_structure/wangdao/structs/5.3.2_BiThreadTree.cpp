typedef struct BiThreadNode
{
    int data;
    BiThreadNode *leftChild, *rightChild;
    int leftTag, rightTag;
} BiThreadNode, *BiThreadTree;

// create an inOrder binary thread tree
void inOrderThreading(BiThreadTree currNode, BiThreadTree &preNode)
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

void createInOrderThread(BiThreadTree t)
{
    BiThreadTree preNode = nullptr;
    if (t != nullptr)
    {
        inOrderThreading(t, preNode);
        preNode->rightChild = nullptr;
        preNode->rightTag = 1;
    }
}

// traverse an inOrder binary thread tree
void visit(BiThreadNode *node);
BiThreadNode *firstNode(BiThreadNode *currNode)
{
    while (currNode->leftTag == 0)
    {
        currNode = currNode->leftChild;
    }
    return currNode;
}
BiThreadNode *nextNode(BiThreadNode *currNode)
{
    if (currNode->rightTag == 0)
    {
        return firstNode(currNode->rightChild);
    }
    return currNode->rightChild;
}
void inOrder(BiThreadTree t)
{
    for (BiThreadNode *currNode = t; currNode != nullptr; currNode = nextNode(currNode))
    {
        visit(currNode);
    }
}