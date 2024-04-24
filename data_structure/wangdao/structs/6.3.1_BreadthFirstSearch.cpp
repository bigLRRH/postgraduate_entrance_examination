#include <queue>
using namespace std;
constexpr int MaxVertexNum = 100;

typedef char VertexType;
typedef int ArcType;
typedef struct
{
    VertexType vertexList[MaxVertexNum];
    int arcMatrix[MaxVertexNum][MaxVertexNum];
    int vertexNum, arcNum;
} AdjacentMatrixGraph;

typedef struct ArcNode
{
    int adjacencyVertexIndex;
    ArcNode *nextArcNode;
} ArcNode;
typedef struct
{
    VertexType vertex;
    ArcNode *firstArc;
} VertexNode;

typedef struct
{
    VertexNode vertexList[MaxVertexNum];
    int vertexNum, arcNum;
} AdjacencyListGraph;

int visit(int i);
void bfsTraverse(AdjacencyListGraph G)
{
    bool isVisited[MaxVertexNum];
    for (int i = 0; i < G.vertexNum; ++i)
    {
        isVisited[i] = false;
    }
    queue<int> q;
    for (int firstBfsIndex = 0; firstBfsIndex < G.vertexNum; ++firstBfsIndex)
    {
        if (!isVisited[firstBfsIndex])
        {
            // bfs
            visit(firstBfsIndex);
            isVisited[firstBfsIndex] = true;
            q.push(firstBfsIndex);
            while (!q.empty())
            {
                int currIndex = q.front();
                q.pop();
                for (ArcNode *arcNode = G.vertexList[currIndex].firstArc; arcNode; arcNode = arcNode->nextArcNode)
                {
                    int currAdjacencyVertexIndex = arcNode->adjacencyVertexIndex;
                    if (!isVisited[currAdjacencyVertexIndex])
                    {
                        visit(currAdjacencyVertexIndex);
                        isVisited[currAdjacencyVertexIndex] = true;
                        q.push(currAdjacencyVertexIndex);
                    }
                }
            }
        }
    }
}

void bfsTraverse(AdjacentMatrixGraph G)
{
    bool isVisited[MaxVertexNum];
    for (int i = 0; i < G.vertexNum; ++i)
    {
        isVisited[i] = false;
    }
    queue<int> q;
    for (int firstBfsIndex = 0; firstBfsIndex < G.vertexNum; ++firstBfsIndex)
    {
        if (!isVisited[firstBfsIndex])
        {
            // bfs
            visit(firstBfsIndex);
            q.push(firstBfsIndex);
            while (!q.empty())
            {
                int currIndex = q.front();
                q.pop();
                for (int j = 0; j < G.vertexNum; ++j)
                {
                    if (!isVisited[j] && G.arcMatrix[currIndex][j])
                    {
                        visit(j);
                        isVisited[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
}

void bfs_min_distance(AdjacencyListGraph G, int startIndex)
{
    bool isVisited[MaxVertexNum];
    for (int i = 0; i < G.vertexNum; ++i)
    {
        isVisited[i] = false;
    }
    // distance[i] represents the distance from startIndex to i
    int distance[MaxVertexNum];
    for (int i = 0; i < G.vertexNum; ++i)
    {
        distance[i] = false;
    }
    queue<int> q;
    isVisited[startIndex] = true;
    distance[startIndex] = 0;
    q.push(startIndex);
    while (!q.empty())
    {
        int currIndex = q.front();
        q.pop();
        for (ArcNode *i = G.vertexList[currIndex].firstArc; i; ++i)
        {
            int adjIndex = i->adjacencyVertexIndex;
            if (!isVisited[adjIndex])
            {
                isVisited[adjIndex] = true;
                distance[adjIndex] = distance[currIndex] + 1;
                q.push(adjIndex);
            }
        }
    }
}

