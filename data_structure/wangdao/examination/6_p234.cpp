#include <queue>
using namespace std;

const constexpr int MaxVertexNum = 100;
typedef char VertexType;
typedef int ArcType;
typedef struct
{
    VertexType vertexList[MaxVertexNum];
    ArcType arcMatrix[MaxVertexNum][MaxVertexNum];
    int vertexNum, arcNum;
} AdjacentMatrixGraph;

typedef struct ArcNode
{
    int adjacentVertexIndex;
    ArcNode *nextArc;
} ArcNode;
typedef struct VertexNode
{
    VertexType vertex;
    ArcNode *firstArc;
} AdjacencyList[MaxVertexNum];
typedef struct
{
    AdjacencyList vertexList;
    int vertexNum, arcNum;
} AdjacencyListGraph;

// 3
bool isTree(AdjacencyListGraph &G)
{
    bool isVisited[MaxVertexNum];
    for (int i = 0; i < G.vertexNum; ++i)
    {
        isVisited[i] = false;
    }
    queue<int> q;
    isVisited[0] = true;
    q.push(0);
    while (!q.empty())
    {
        int currIndex = q.front();
        q.pop();

        for (ArcNode *i = G.vertexList[currIndex].firstArc; i; i = i->nextArc)
        {
            int adjIndex = i->adjacentVertexIndex;
            if (isVisited[adjIndex])
                return false;
            else
            {
                isVisited[adjIndex] = true;
                q.push(adjIndex);
            }
        }
    }
    return true;
}

bool isTree(AdjacentMatrixGraph &G, int currIndex, bool isVisited[MaxVertexNum] = {0})
{
    isVisited[currIndex] = true;
    for (int i = 0; i < G.vertexNum; ++i)
    {
        if (G.arcMatrix[currIndex][i])
        {
            if (isVisited[i])
            {
                return false;
            }
            else
            {
                // !会过早返回true导致没有遍历所有结点
                // return isTree(G, i, isVisited);
                if (!isTree(G, i, isVisited))
                    return false;
            }
        }
    }
    return true;
}

// 4
bool hasPath_bfs(AdjacencyListGraph G, int i, int j)
{
    bool isVisited[MaxVertexNum];
    for (int k = 0; k < G.vertexNum; ++k)
    {
        isVisited[k] = false;
    }
    queue<int> q;
    isVisited[i] = true;
    q.push(i);
    while (!q.empty())
    {
        int currIndex = q.front();
        q.pop();
        for (ArcNode *arc = G.vertexList[currIndex].firstArc; arc; arc = arc->nextArc)
        {
            int adjIndex = arc->adjacentVertexIndex;
            if (!isVisited[adjIndex])
            {
                if (adjIndex == j)
                    return true;
                isVisited[adjIndex] = true;
                q.push(adjIndex);
            }
        }
    }
    return false;
}

bool dfs4(AdjacencyListGraph &G, int currIndex, int j, bool isVisited[MaxVertexNum])
{
    // i != j
    if (currIndex == j)
    {
        return true;
    }
    isVisited[currIndex] = true;
    for (ArcNode *arc = G.vertexList[currIndex].firstArc; arc; arc = arc->nextArc)
    {
        int adjIndex = arc->adjacentVertexIndex;
        if (!isVisited[adjIndex])
        {
            // if (adjIndex == j)
            //     return true;
            if (dfs4(G, adjIndex, j, isVisited))
                return true;
        }
    }
    return false;
}
bool hasPath_dfs(AdjacencyListGraph &G, int i, int j)
{
    bool isVisited[MaxVertexNum];
    for (int k = 0; k < G.vertexNum; ++k)
    {
        isVisited[k] = false;
    }
    return dfs4(G, i, j, isVisited);
}

// 5
void printAllPath(AdjacencyListGraph &G, int v1, int v2, int path[MaxVertexNum], int distance)
{
}