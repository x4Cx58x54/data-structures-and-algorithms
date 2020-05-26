/*
    Max sparse table.
*/

#include <algorithm>

template<typename type>
class SparseTable
{
private:
    size_t size;
    int *Log2;
    type (*st)[21];
public:
    type query(int l, int r)
    {
        int s = Log2[r - l + 1];    // l + 2^s - 1 <= r
        return std::max(st[l][s], st[r - (1 << s) + 1][s]);
    }
    SparseTable(size_t _size, type *data)
    {
        size = _size;
        st = new type[size+1][21];
        Log2 = new int[size+1];
        Log2[1] = 0;
        for(int i = 2; i <= size; ++i)
            Log2[i] = Log2[i>>1] + 1;
        for(int i = 1; i <= size; ++i)
            st[i][0] = data[i];
        for(int j = 1; j < 21; ++j)
            for(int i = 1; i + (1 << j) - 1 <= size; ++i)
                st[i][j] = std::max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
    }
    ~SparseTable()
    {
        delete Log2;
        delete st;
    }
};
