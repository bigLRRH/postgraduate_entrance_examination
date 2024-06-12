// static string
#define MAXSTRLEN 255
typedef struct
{
    char ch[MAXSTRLEN];
    int length;
} StaticString;

// heap string
typedef struct
{
    char *ch;
    int length;
} HString;
