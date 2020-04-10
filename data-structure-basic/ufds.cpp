/*
    Union-Find Disjoint Sets with path compression.
*/

class ufds
{
private:
    int *father;
public:
    int Ancestor(int a)
    {
        if (father[a] == a) return a;
        father[a] = Ancestor(father[a]);
        return father[a];
    }
    inline int UnionSet(int a, int b)
    {
        father[Ancestor(a)] = Ancestor(b);
    }
    inline bool IsSameSet(int a, int b)
    {
        return Ancestor(a) == Ancestor(b);
    }
    ufds(int n)
    {
        father = new int[n];
        for(int i = 0; i < n; i++) father[i] = i;
    }
    ~ufds()
    {
        delete father;
    }
};
