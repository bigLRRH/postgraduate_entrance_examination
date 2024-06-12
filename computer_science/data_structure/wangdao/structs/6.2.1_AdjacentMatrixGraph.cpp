#define MaxVertexNum 100
typedef char VertexType;
typedef int ArcType;
typedef struct
{
    VertexType vertex[MaxVertexNum];
    ArcType arc[MaxVertexNum][MaxVertexNum];
    int vertexNum, arcNum;
} MatrixGraph;

