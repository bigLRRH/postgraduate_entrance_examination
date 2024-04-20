#define MaxVertexNum 100
typedef char VertexType;
typedef struct ArcNode
{
    int vertexIndex;
    // int weight;
    ArcNode *nextArc;
};
typedef struct VertexNode
{
    VertexType vertex;
    ArcNode *firstArc;
} VertexNode, AdjacencyList[MaxVertexNum];
typedef struct
{
    AdjacencyList vertices;
    int vertexNum, arcNum;
} AdjacencyListGraph;
