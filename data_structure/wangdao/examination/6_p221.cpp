#define MaxVertexNum 100
typedef char VertexType;
typedef int ArcType;

typedef struct
{
    VertexType vertex[MaxVertexNum];
    ArcType arc[MaxVertexNum][MaxVertexNum];
    int vertexNum, arcNum;
} AdjacentMatrix;

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
    AdjacencyList vertex[MaxVertexNum];
    int vertexNum, arcNum;
} AdjacencyListGraph;

// 5
AdjacentMatrix convert_AdjacencyListGraph_to_AdjacentMatrix(AdjacencyListGraph g)
{

}