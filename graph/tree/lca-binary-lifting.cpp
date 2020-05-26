/*
    Lowest common ancestor of a binary tree, using binary lifting, on linked forward star.
*/

const int maxn = 1000;
const int maxm = 10000;
int head[maxn];
struct { int to, next; } edge[maxm+1]; // linked forward star
int root;

// Initialize graph

int father[maxn][21], Log2[maxn], depth[maxn];
bool vis[maxn];

void initlog()
{
    for(int i = 2; i < maxn; ++i)
        Log2[i] = Log2[i >> 1] + 1;
}

void dfs(int cur, int fa)
{
    if (vis[cur]) return;
    vis[cur] = true;
    depth[cur] = depth[fa] + 1;
    father[cur][0] = fa;
    for(int i = 1; i <= Log2[depth[cur]]; ++i)
        father[cur][i] = father[father[cur][i-1]][i-1];
    for(int i = head[cur]; i; i = edge[i].next)
        dfs(edge[i].to, cur);
}

int lca(int a, int b)
{
    if (depth[a] > depth[b]) { int temp = a; a = b; b = temp; }
    while(depth[a] < depth[b]) b = father[b][Log2[depth[b] - depth[b]]];
    if (a == b) return a;
    for(int k = Log2[depth[a]]; k >= 0; --k)
        if (father[a][k] != father[b][k])
        {
            a = father[a][k];
            b = father[b][k];
        }
    return father[a][0];
}

/*
    Initialization:
        initlog();
        dfs(root, 0);
    Query:
        lca(a, b);
*/
