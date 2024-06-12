#define MaxVertexNum 100
#include <cstdio>
typedef char VertexType;
typedef int ArcType;

typedef struct
{
    VertexType vertexList[MaxVertexNum];
    ArcType arcMatrix[MaxVertexNum][MaxVertexNum];
    int vertexNum, arcNum;
} AdjacentMatrixGraph;

// ==========================================
typedef struct ArcNode
{
    int vertexIndex;
    // int weight;
    ArcNode *nextNode;
};

typedef struct VertexNode
{
    VertexType vertex;
    ArcNode *firstNode;
} AdjacencyList;

typedef struct
{
    AdjacencyList vertexList[MaxVertexNum];
    int vertexNum, arcNum;
} AdjacencyListGraph;

// 5
AdjacentMatrixGraph convert_AdjacencyListGraph_to_AdjacentMatrix(AdjacencyListGraph g)
{
    AdjacentMatrixGraph resultGraph;
    resultGraph.vertexNum = g.vertexNum;
    resultGraph.arcNum = g.arcNum;
    for (int i = 0; i < g.vertexNum; ++i)
    {
        resultGraph.vertexList[i] = g.vertexList[i].vertex;
        ArcNode *currNode = g.vertexList[i].firstNode;
        while (currNode)
        {
            resultGraph.arcMatrix[i][currNode->vertexIndex] = 1;
            currNode = currNode->nextNode;
        }
    }
    return resultGraph;
}

// ======================================================
#define MaxV 100
typedef struct
{
    int numVertices, numEdges;
    char VerticesList[MaxV];
    int Edge[MaxV][MaxV];
} MGraph;
// 7
int IsExistEL(MGraph G)
{
    int count_node_with_odd_degree = 0;
    for (int i = 0; i < MaxV; ++i)
    {
        int countDegree = 0;
        for (int j = 0; j < MaxV; ++j)
        {
            if (G.Edge[i][j])
            {
                ++countDegree;
            }
        }
        if (countDegree % 2)
        {
            ++count_node_with_odd_degree;
        }
    }
    if (count_node_with_odd_degree == 0 || count_node_with_odd_degree == 2)
        return false;
    else
        return true;
}

// 8
int printVertices(MGraph G)
{
    int countK{0};
    for (int i = 0; i < MaxV; ++i)
    {
        int countInDegree{0}, countOutDegree{0};
        for (int j = 0; j < MaxV; ++j)
        {
            if (G.Edge[i][j])
            {
                ++countOutDegree;
            }
            if (G.Edge[j][i])
            {
                ++countInDegree;
            }
        }
        if (countOutDegree > countInDegree)
        {
            printf("%c", G.VerticesList[i]);
            ++countK;
        }
    }
    return countK;
}