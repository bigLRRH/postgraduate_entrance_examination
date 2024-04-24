const constexpr int MaxVertexNum = 100;
typedef char VertexType;
typedef struct
{
    VertexType vertexList[MaxVertexNum];
    int arcMatrix[MaxVertexNum][MaxVertexNum];
    int vertexNum, arcNum;
} AdjacentMatrixGraph;

typedef struct ArcNode
{
    int AdjacentVertexIndex;
    // int weight;
    ArcNode *nextArcNode;
} ArcNode;
typedef struct
{
    VertexType vertex;
    ArcNode *firstArcNode;
} VertexNode, AdjacencyList[MaxVertexNum];
typedef struct
{
    AdjacencyList vertexList;
    int vertexNum, arcNum;
} AdjacencyListGraph;
void visit(int vertexIndex);
void dfs(AdjacencyListGraph &G, int currIndex, int isVisited[MaxVertexNum])
{
    visit(currIndex);
    isVisited[currIndex] = true;
    for (ArcNode *p = G.vertexList[currIndex].firstArcNode; p; p = p->nextArcNode)
    {
        int adjIndex = p->AdjacentVertexIndex;
        if (!isVisited[adjIndex])
        {
            dfs(G, adjIndex, isVisited);
        }
    }
}
void dfs(AdjacentMatrixGraph &G, int currINdex, int isVisited[MaxVertexNum])
{
    visit(currINdex);
    isVisited[currINdex] = true;
    for (int i = 0; i < G.vertexNum; ++i)
    {
        if (G.arcMatrix[currINdex][i] && !isVisited[i])
        {
            dfs(G, i, isVisited);
        }
    }
}