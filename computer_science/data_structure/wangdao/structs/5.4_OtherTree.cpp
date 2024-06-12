#define MAXSIZE 100

//
typedef struct
{
    int data;
    int parent;
} ParentTreeNode;
typedef struct
{
    ParentTreeNode nodes[MAXSIZE];
    int n;
} ParentTree;

//
typedef struct ChildSiblingTreeNode
{
    int data;
    ChildSiblingTreeNode *firstChild, *nextSibling;
} ChildSiblingTreeNode, *ChildSiblingTree;

//
