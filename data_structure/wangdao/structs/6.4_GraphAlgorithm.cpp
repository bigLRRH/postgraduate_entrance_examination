#include <cstdio>
const constexpr int MAX_VERTEX_NUM = 100;

typedef char VertexType;
typedef int ArcType;
typedef struct
{
    VertexType vertexList[MAX_VERTEX_NUM];
    ArcType arcMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vertexNum, arcNUm;
} AdjacentMatrixGraph;

int locateVertex(AdjacentMatrixGraph G, VertexType v)
{
    for (int i = 0; i < G.vertexNum; ++i)
    {
        if (G.vertexList[i] == v)
        {
            return i;
        }
    }
    return -1;
}

// Prim
struct CloseEdge
{
    VertexType adjVertex;
    int lowestCost;
}; // auxiliary array

int minimum_index(CloseEdge closeEdge[MAX_VERTEX_NUM], int size)
{
    int min_index = 0;
    for (int i = 1; i < size; ++i)
    {
        if (closeEdge[i].lowestCost != -1 && closeEdge[i].lowestCost < closeEdge[min_index].lowestCost)
        {
            min_index = i;
        }
    }
    return min_index;
}

void minimum_spanning_cost_tree_Prim(AdjacentMatrixGraph G, VertexType u)
{
    int k = locateVertex(G, u);
    CloseEdge closeEdge[MAX_VERTEX_NUM];
    // initialize auxiliary array
    for (int j = 0; j < G.vertexNum; ++j)
    {
        if (j != k)
        {
            closeEdge[j] = {u, G.arcMatrix[k][j]};
        }
    }
    closeEdge[k].lowestCost = 0;
    for (int i = 0; i < G.vertexNum; ++i)
    {
        k = minimum_index(closeEdge, G.vertexNum);
        printf("%c %c\n", closeEdge[k].adjVertex, G.vertexList[k]);
        closeEdge[k].lowestCost = 0;
        for (int j = 0; j < G.vertexNum; ++j)
        {
            if (G.arcMatrix[k][j] != -1 && G.arcMatrix[k][j] < closeEdge[j].lowestCost)
            {
                closeEdge[j] = {G.vertexList[k], G.arcMatrix[k][j]};
            }
        }
    }
}
// tn = O(v^2)