/*
    Sum segment tree, update by adding.
    data[] ranges from 1 to size (included).
*/

template<typename type>
class SumSegmentTree
{
private:
    size_t size;
    type *stree, *lazy, *data;
public:
    void build(int l, int r, int p)
    {
        if (l == r) stree[p] = data[l];
        else
        {
            int mid = (l + r) / 2;
            build(l, mid, p*2);
            build(mid+1, r, p*2+1);
            stree[p] = stree[p*2] + stree[p*2+1];
        }
    }
    void pushdown(int p, int cl, int cr, int cmid)
    {
        stree[p*2] += (cmid - cl + 1) * lazy[p];
        stree[p*2+1] += (cr - cmid) * lazy[p];
        lazy[p*2] += lazy[p];
        lazy[p*2+1] += lazy[p];
        lazy[p] = 0;
    }
    void add(int l, int r, type k, int cl, int cr, int p)
    {
        if (l <= cl && cr <= r)
        {
            stree[p] += (cr - cl + 1) * k;
            lazy[p] += k;
            return;
        }
        if (cr < l || r < cl) return;
        int cmid = (cl + cr) / 2;
        pushdown(p, cl, cr, cmid);
        add(l, r, k, cl, cmid, p*2);
        add(l, r, k, cmid+1, cr, p*2+1);
        stree[p] = stree[p*2] + stree[p*2+1];
    }
    int query(int l, int r, int cl, int cr, int p)
    {
        if (l <= cl && cr <= r)
            return stree[p];
        else if (cr < l || r < cl)
            return 0;
        int cmid = (cl + cr) / 2;
        pushdown(p, cl, cr, cmid);
        return query(l, r, cl, cmid, p*2) + query(l, r, cmid+1, cr, p*2+1);
    }
    SumSegmentTree(size_t _size, type *_data)
    {
        size = _size;
        data = _data;
        stree = new type[4*_size+1]();
        lazy = new type[4*_size+1]();
    }
    ~SumSegmentTree()
    {
        delete stree;
        delete lazy;
    }
};
