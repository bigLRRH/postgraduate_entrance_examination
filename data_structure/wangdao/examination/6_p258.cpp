#include <cstdio>
const constexpr int MAX_VERTEX_NUM = 100;
typedef char VertexType;
typedef int ArcType;
typedef struct
{
    VertexType vertexList[MAX_VERTEX_NUM];
    ArcType ArcMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vertexNum, arcNum;
} AdjacentMatrixGraph;

typedef struct ArcNode
{
    int adjacentVertexIndex;
    ArcNode *nextArcNode;
} ArcNode;
typedef struct VertexNode
{
    VertexType vertex;
    ArcNode *firstArcNode;
} VertexNode, VertexList[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
    VertexList vertexList;
    int vertexNum, arcNum;
} AdjacencyListGraph;

// 7
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void reverse(int a[MAX_VERTEX_NUM], int length)
{
    for (int i = 0; i < length / 2; ++i)
    {
        swap(a[i], a[length - i - 1]);
    }
}
void topologicalOrderDFS(AdjacencyListGraph &G, int vertexIndex, int isVisited[MAX_VERTEX_NUM],
                         int topologicalOrderArray[MAX_VERTEX_NUM], int &topologicalOrderIndex)
{
    isVisited[vertexIndex] = true;
    for (ArcNode *arcNode = G.vertexList[vertexIndex]->firstArcNode; arcNode; arcNode = arcNode->nextArcNode)
    {
        int adjVex = arcNode->adjacentVertexIndex;
        topologicalOrderDFS(G, adjVex, isVisited);
    }
    topologicalOrderArray[topologicalOrderIndex++] = vertexIndex;
}
void topologicalOrderDFS(AdjacencyListGraph &G, int vertexIndex, int topologicalOrderArray[MAX_VERTEX_NUM])
{
    // initial
    int isVisited[MAX_VERTEX_NUM];
    int topologicalOrderIndex = 0;
    for (int i = 0; i < G.vertexNum; ++i)
    {
        isVisited[i] = false;
    }
    // dfs
    topologicalOrderDFS(G, vertexIndex, isVisited, topologicalOrderArray, topologicalOrderIndex);
    // reverse
    reverse(topologicalOrderArray, G.vertexNum);
}

// 9