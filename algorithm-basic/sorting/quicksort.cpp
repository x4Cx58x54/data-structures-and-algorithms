/*
    Quicksort a[l..r], l and r included.
*/

template<typename type>
inline int Partition(type a[], int l, int r)
{
    type pivot = a[l];
    while(l < r)
    {
        while(l < r && a[r] >= pivot)
            r--;
        a[l] = a[r];
        while(l < r && a[l] <= pivot)
            l++;
        a[r] = a[l];
    }
    a[l] = pivot;
    return l;
}

template<typename type>
void Quicksort(type a[], int l, int r)
{
    if (l >= r) return;
    int p = Partition<type>(a, l, r);
    Quicksort(a, l, p-1);
    Quicksort(a, p+1, r);
}
