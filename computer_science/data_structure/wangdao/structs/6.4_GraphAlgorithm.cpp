#include <cstdio>
#include <limits>
#include <stack>
using namespace std;
const constexpr int MAX_VERTEX_NUM = 100;

typedef char VertexType;
typedef int ArcType;
typedef struct
{
    VertexType vertexList[MAX_VERTEX_NUM];
    ArcType arcMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vertexNum, arcNUm;
} AdjacentMatrixGraph;

int locateVertex(AdjacentMatrixGraph &G, VertexType v)
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

typedef struct ArcNode
{
    int adjacentVertexIndex;
    int info;
    ArcNode *nextArc;
} ArcNode;
typedef struct VertexNode
{
    VertexType vertex;
    ArcNode *firstArc;
} AdjacencyList[MAX_VERTEX_NUM];
typedef struct
{
    AdjacencyList vertexList;
    int vertexNum, arcNum;
} AdjacencyListGraph;

// Prim
struct CloseEdge
{
    VertexType adjVertex;
    int lowestCost;
}; // auxiliary array

int min_lowestCost_index(CloseEdge closeEdge[MAX_VERTEX_NUM], int size)
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
void minimumSpanningCostTree_Prim(AdjacentMatrixGraph &G, VertexType u)
{
    int k = locateVertex(G, u);
    CloseEdge closeEdge[MAX_VERTEX_NUM];
    // initialize auxiliary array
    for (int i = 0; i < G.vertexNum; ++i)
    {
        if (i != k)
        {
            closeEdge[i] = {u, G.arcMatrix[k][i]};
        }
    }
    closeEdge[k].lowestCost = 0;
    for (int i = 0; i < G.vertexNum; ++i)
    {
        k = min_lowestCost_index(closeEdge, G.vertexNum);
        // this moment
        // closeEdge[k].lowestCost = MIN{ closeEdge[v].lowestCost | closeEdge[v].lowestCost>0 , v ∈ V-U }
        printf("%c %c\n", closeEdge[k].adjVertex, G.vertexList[k]);
        closeEdge[k].lowestCost = 0;
        for (int j = 0; j < G.vertexNum; ++j)
        {
            if (G.arcMatrix[k][j] > 0 && G.arcMatrix[k][j] < closeEdge[j].lowestCost)
            {
                closeEdge[j] = {G.vertexList[k], G.arcMatrix[k][j]};
            }
        }
    }
}
// tn = O(v^2)

// Kruskal
typedef int UnionFindSet[MAX_VERTEX_NUM];
int fix(UnionFindSet ufSet, int x)
{
    if (x < 1 || x >= MAX_VERTEX_NUM)
        return -1;
    int root = x;
    while (ufSet[root] >= 0)
    {
        root = ufSet[root];
    }
    while (x != root)
    {
        int temp = ufSet[x];
        ufSet[x] = root;
        x = temp;
    }
    return root;
}
void mix(UnionFindSet ufSet, int i, int j)
{
    if (i == j)
    {
        return;
    }
    if (ufSet[j] > ufSet[i])
    {
        ufSet[i] += ufSet[j];
        ufSet[j] = i;
    }
    else
    {
        ufSet[j] += ufSet[i];
        ufSet[i] = j;
    }
}

void minimumSpanningCostTree_Kruskal(AdjacentMatrixGraph &G, VertexType u)
{
    // todo sort edges
}

// Dijkstra
void shortestPath_Dijkstra(AdjacentMatrixGraph &G, int v0, bool pathList[MAX_VERTEX_NUM][MAX_VERTEX_NUM], int final[MAX_VERTEX_NUM])
{
    int min_distance[MAX_VERTEX_NUM];
    // initial
    for (int i = 0; i < G.vertexNum; ++i)
    {
        final[i] = false;
        min_distance[i] = G.arcMatrix[v0][i];
        for (int j = 0; j < G.vertexNum; ++j)
        {
            pathList[i][j] = false;
        }
        if (min_distance[i] != -1)
        {
            pathList[i][v0] = true;
            pathList[i][i] = true;
        }
    }
    min_distance[v0] = 0;
    final[v0] = true;

    // main loop
    for (int i = 0; i < G.vertexNum; ++i)
    {
        // find closest v
        int v;
        int min = -1;
        for (int j = 0; j < G.vertexNum; ++j)
        {
            if (!final[j])
            {
                if (min == -1 || (min_distance[j] != -1 && min_distance[j] < min))
                {
                    v = j;
                    min = min_distance[j];
                }
            }
        }
        final[v] = true;

        // update min_distance and pathList
        for (int j = 0; j < G.vertexNum; ++j)
        {
            if (!final[j] && G.arcMatrix[v][j] != -1 &&
                (min_distance[j] == -1 || (min + G.arcMatrix[v][j] < min_distance[j])))
            {
                min_distance[j] = min + G.arcMatrix[v][j];
                for (int k = 0; k < G.vertexNum; ++k)
                {
                    pathList[j][k] = pathList[v][k];
                }
                pathList[j][j] = true;
            }
        }
    }
}
// tn=O(v^2) no pathList

// Floyd
void shortestPath_Floyd(AdjacentMatrixGraph &G, bool pathList[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM], int distance[MAX_VERTEX_NUM][MAX_VERTEX_NUM])
{
    // initial
    for (int i = 0; i < G.vertexNum; ++i)
    {
        for (int j = 0; j < G.vertexNum; ++j)
        {
            distance[i][j] = G.arcMatrix[i][j];
            for (int k = 0; k < G.vertexNum; ++k)
            {
                pathList[i][j][k] = false;
            }
            if (distance[i][j] != -1)
            {
                pathList[i][j][i] = true;
                pathList[i][j][j] = true;
            }
        }
    }
    // main loop
    for (int k = 0; k < G.vertexNum; ++k)
    {
        for (int i = 0; i < G.vertexNum; ++i)
        {
            for (int j = 0; j < G.vertexNum; ++j)
            {
                if (distance[i][k] != -1 && distance[k][j] != -1 && distance[i][k] + distance[k][j] < distance[i][j])
                {
                    for (int r = 0; r < G.vertexNum; ++r)
                    {
                        pathList[i][j][r] = pathList[i][k][r] || pathList[k][j][r];
                    }
                }
            }
        }
    }
}
// tn=O(v^3) no pathList

// topologicalSort
void findInDegree(AdjacencyListGraph &G, int inDegree[MAX_VERTEX_NUM])
{
    for (int i = 0; i < G.vertexNum; ++i)
    {
        inDegree[i] = 0;
    }

    for (int i = 0; i < G.vertexNum; ++i)
    {
        for (ArcNode *currArcNode = G.vertexList[i].firstArc; currArcNode; currArcNode = currArcNode->nextArc)
        {
            ++inDegree[currArcNode->adjacentVertexIndex];
        }
    }
}

bool topologicalSort(AdjacencyListGraph &G)
{
    int inDegree[MAX_VERTEX_NUM];
    findInDegree(G, inDegree);
    stack<int> s;
    for (int i = 0; i < G.vertexNum; ++i)
    {
        if (inDegree[i] == 0)
        {
            s.push(i);
        }
    }
    int count = 0;
    while (!s.empty())
    {
        int currIndex = s.top();
        s.pop();
        printf("%d %c\n", currIndex, G.vertexList[currIndex].vertex);
        ++count;
        for (ArcNode *currArcNode = G.vertexList[currIndex].firstArc; currArcNode; currArcNode = currArcNode->nextArc)
        {
            int adjVex = currArcNode->adjacentVertexIndex;
            if (--inDegree[adjVex] == 0)
            {
                s.push(adjVex);
            }
        }
    }
    if (count < G.vertexNum)
        return false;
    else
        return true;
}

// CriticalPath
bool topologicalOrder(AdjacencyListGraph &G, stack<int> &T, int ve[MAX_VERTEX_NUM])
{
    int inDegree[MAX_VERTEX_NUM];
    findInDegree(G, inDegree);
    stack<int> s;
    for (int i = 0; i < G.vertexNum; ++i)
    {
        if (inDegree[i] == 0)
            s.push(i);
    }

    int count = 0;
    for (int i = 0; i < G.vertexNum; ++i)
    {
        ve[i] = 0;
    }
    while (!s.empty())
    {
        int currIndex = s.top();
        s.pop();
        T.push(currIndex);
        ++count;
        for (ArcNode *currArcNode = G.vertexList[currIndex].firstArc; currArcNode; currArcNode = currArcNode->nextArc)
        {
            int adjVex = currArcNode->adjacentVertexIndex;
            if (--inDegree[adjVex] == 0)
            {
                s.push(adjVex);
            }
            int durationTime = currArcNode->info;
            if (ve[currIndex] + durationTime > ve[adjVex])
            {
                ve[adjVex] = ve[currIndex] + durationTime;
            }
        }
    }
    if (count < G.vertexNum)
        return false;
    else
        return true;
}
bool criticalPath(AdjacencyListGraph &G)
{
    int ve[MAX_VERTEX_NUM];
    stack<int> T;
    if (!topologicalOrder(G, T, ve))
        return false;
    int vl[MAX_VERTEX_NUM];
    for (int i = 0; i < G.vertexNum; ++i)
    {
        vl[i] = ve[G.vertexNum - 1 - i];
    }
    while (!T.empty())
    {
        int currIndex = T.top();
        T.pop();
        for (ArcNode *currArcNode = G.vertexList[currIndex].firstArc; currArcNode; currArcNode = currArcNode->nextArc)
        {
            int adjVex = currArcNode->adjacentVertexIndex;
            int durationTime = currArcNode->info;
            if (vl[adjVex] - durationTime < vl[currIndex])
            {
                vl[currIndex] = vl[adjVex] - durationTime;
            }
        }
    }
    for (int i = 0; i < G.vertexNum; ++i)
    {
        for (ArcNode *currArcNode = G.vertexList[i].firstArc; currArcNode; currArcNode = currArcNode->nextArc)
        {
            int adjVex = currArcNode->adjacentVertexIndex;
            int durationTime = currArcNode->info;
            int e = ve[i];
            int l = vl[adjVex] - durationTime;
            char tag = (e == l) ? '*' : ' ';
            printf("%d %d %d %d %d %c\n", i, adjVex, durationTime, e, l, tag);
        }
    }
    return true;
}