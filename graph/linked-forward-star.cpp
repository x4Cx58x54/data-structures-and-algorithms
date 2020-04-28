/*
    Linked forward star, adjacency list
*/

#include <string.h>

struct Edge { int to, w, next; };
class Graph
{
public:
    int top;
    int *head;
    Edge *edge;
    Graph(int maxvertex, int maxedge)
    {
        head = new int[maxvertex+1]();
        edge = new Edge[maxedge+1];
        top = 1;
    }
    void addedge(int from, int to, int w)
    {
        edge[top].to = to;
        edge[top].w = w;
        edge[top].next = head[from];
        head[from] = top++;
    }

    // Adjecent vertex from x;
    void clear() { memset(head, 0, sizeof(head)); top = 1; }
    void traversal(int x)
    {
        for(int i = head[x]; i; i = edge[i].next)
        {
            // Do something.
            // edge[i].to is the vertex adjcent to x
        }
    }
};
