/*
    Hungarian algorithm on bipartite graph.
*/

#include <string.h>

const int M = 1001, N = 1001; // Number of vertices on left and right
bool map[M][N]; // Adjcency matric, starting from 1.
bool vis[N];
int leftof[N];

bool match(int i)
{
    for(int j = 0; j <= N; ++j)
    {
        if (map[i][j] && !vis[j])
        {
            vis[j] = true;
            if (leftof[j] == 0 || match(leftof[j]))
            {
                leftof[j] = i;
                return true;
            }
        }
    }
    return false;
}

int Hungarian()
{
    int cnt = 0;
    for(int i = 1; i <= M; ++i)
    {
        memset(vis, false, sizeof(vis));
        if (match(i)) ++cnt;
    }
    return cnt;
}
