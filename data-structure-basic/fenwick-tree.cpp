/*
    Fenwick tree
*/

template <typename type>
class Fenwick
{
private:
    type *data;
    int size;
    int lowbit(int x)
    {
        return x & -x;
    }
public:
    int add(int pos, type k)
    {
        while(pos <= size)
        {
            data[pos] += k;
            pos += lowbit(pos);
        }
    }
    type sum(int r)
    {
        type res = 0;
        while(r >= 1)
        {
            res += data[r];
            r -= lowbit(r);
        }
        return res;
    }
    type sum(int l, int r)
    {
        return sum(r) - sum(l-1);
    }
    Fenwick(int n)
    {
        data = new type[n+1];
        size = n;
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    ~Fenwick()
    {
        delete data;
    }
};
