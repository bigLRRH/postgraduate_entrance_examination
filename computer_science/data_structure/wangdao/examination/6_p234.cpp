#include <cstdio>
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
    int count_traverse_node = 1;
    int count_traverse_edge = 0;
    isVisited[0] = true;
    q.push(0);
    while (!q.empty())
    {
        int currIndex = q.front();
        q.pop();

        for (ArcNode *i = G.vertexList[currIndex].firstArc; i; i = i->nextArc)
        {
            int adjIndex = i->adjacentVertexIndex;
            // ! 上个结点也有可能return false
            // if (isVisited[adjIndex])
            //     return false;
            // else
            // {
            //     isVisited[adjIndex] = true;
            //     ++count_traverse_node;
            //     q.push(adjIndex);
            // }
            ++count_traverse_edge;
            if (!isVisited[adjIndex])
            {
                isVisited[adjIndex] = true;
                ++count_traverse_node;
                q.push(adjIndex);
            }
        }
    }
    return count_traverse_node == G.vertexNum && count_traverse_edge / 2 == G.arcNum - 1;
}

void isTree_dfs(AdjacentMatrixGraph &G, int currIndex, int &count_vertex, int &count_edge, bool isVisited[MaxVertexNum] = {0})
{
    ++count_vertex;
    isVisited[currIndex] = true;
    for (int i = 0; i < G.vertexNum; ++i)
    {
        if (G.arcMatrix[currIndex][i])
        {
            ++count_edge;
            if (!isVisited[i])
            {
                // !会过早返回true导致没有遍历所有结点
                // return isTree(G, i, isVisited);
                isTree_dfs(G, i, count_vertex, count_edge, isVisited);
            }
        }
    }
}
bool isTree(AdjacentMatrixGraph &G)
{
    int count_vertex = 0, count_edge = 0;
    bool isVisited[MaxVertexNum];
    for (int i = 0; i < G.vertexNum; ++i)
    {
        isVisited[i] = false;
    }
    isTree_dfs(G, 0, count_vertex, count_edge, isVisited);
    if (count_vertex == G.vertexNum && count_edge / 2 == G.arcNum - 1)
        return true;
    else
        return false;
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
void dfsPrintAllPath(AdjacencyListGraph &G, int currIndex, int v2,
                     int path[MaxVertexNum], bool isVisited[MaxVertexNum], int distance = 0)
{
    path[distance] = currIndex;
    if (currIndex == v2)
    {
        for (int i = 0; i <= distance; ++i)
        {
            printf("%d", path[i]);
        }
        printf("\n");
    }
    isVisited[currIndex] = true;
    for (ArcNode *arc = G.vertexList[currIndex].firstArc; arc; arc = arc->nextArc)
    {
        int adjIndex = arc->adjacentVertexIndex;
        if (!isVisited[adjIndex])
        {
            dfsPrintAllPath(G, adjIndex, v2, path, isVisited, distance + 1);
        }
    }
    isVisited[currIndex] = false;
}
void printAllPath(AdjacencyListGraph &G, int v1, int v2)
{
    int path[MaxVertexNum];
    bool isVisited[MaxVertexNum];
    for (int i = 0; i < G.vertexNum; ++i)
    {
        path[i] = -1;
        isVisited[i] = false;
    }
    dfsPrintAllPath(G, v1, v2, path, isVisited, 0);
}