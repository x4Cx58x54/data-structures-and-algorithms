#include <iostream>
using namespace std;

struct slist
{
    int data;
    int next;
};


// Insert Sort
void InsertSort(int[], int, int);
void BinaryInsertSort(int[], int, int);
void TwoWaysInsertSort(slist[], int);
void TableInsertSort(slist[], int);

// Bubble Sort
void BubbleSort(int[], int, int);
// Quick Sort
int Partition(int[], int, int);
void QuickSort(int[], int, int);

// Selection Sort
void SelectionSort(int[], int, int);
// Heap Sort
void HeapAdjust(int[], int, int);
void HeapSort(int[], int);

// Merge Sort
void Merge(int[], int, int, int);
void MergeSort(int[], int, int);

//Radix Sort


int main()
{
    int a[]={0,8,3,4,2,1,6,0,7,9,5};
    int maxbound=sizeof(a)/sizeof(int)-1;

    slist s[11];
    for(int i=0; i<=11; i++) s[i].data=a[i];

    //InsertSort(a, 1, maxbound);
    //BinaryInsertSort(a, 1, maxbound);
    //BubbleSort(a, 1, maxbound);
    //QuickSort(a, 1, maxbound);
    //SelectionSort(a, 1, maxbound);
    //HeapSort(a, maxbound);
    //MergeSort(a, 1, maxbound);

    for(int i=1;i<=maxbound;i++)
        cout<<a[i]<<"  ";
    return 0;
}

void InsertSort(int a[], int l, int r)
{
    int p, temp;
    for(int i=l+1; i<=r; i++)
    {
        p=i-1;
        while(a[p]>a[i] && p>=l)
            p--;
        temp=a[i];
        for(int j=i-1; j>=p+1; j--)
            a[j+1]=a[j];
        a[p+1]=temp;
    }
}

void BinaryInsertSort(int a[], int l, int r)
{
    int temp;
    for(int i=l+1; i<=r; i++)
    {
        temp=a[i];
        int low=l, high=i-1;
        while(low<=high)
        {
            int mid=(high+low)/2;
            if (a[mid]>a[i])
                high=mid-1;
            else
                low=mid+1;
        }
        for(int j=i-1; j>=high+1; j--)
            a[j+1]=a[j];
        a[high+1]=temp;
    }
}


void BubbleSort(int a[], int l, int r)
{
    for(int i=r; i>=l; i--)
    {
        bool change=false;
        for(int j=l; j<=i-1; j++)
            if (a[j]>a[j+1])
            {
                swap(a[j], a[j+1]);
                change=true;
            }
        if (change=false) break;
    }
}

int Partition(int a[], int l, int r)
{
    int pivot=a[l];
    while(l<r)
    {
        while(l<r && a[r]>=pivot)
            r--;
        a[l]=a[r];
        while(l<r && a[l]<=pivot)
            l++;
        a[r]=a[l];
    }
    a[l]=pivot;
    return l;
}

void QuickSort(int a[], int l, int r)
{
    if (l<r)
    {
        int p=Partition(a, l, r);
        QuickSort(a, l, p-1);
        QuickSort(a, p+1, r);
    }
    return;
}

void SelectionSort(int a[], int l, int r)
{
    for(int i=l; i<=r-1; i++)
    {
        int minValue=a[i];
        int minLocation=i;
        for(int j=i+1; j<=r; j++)
        {
            if (a[j]<minValue)
            {
                minValue=a[j];
                minLocation=j;
            }
        }
        if (minLocation!=i)
            swap(a[i], a[minLocation]);
    }
}

void HeapAdjust(int a[], int p, int r) // a[p+1..r] is a heap, and add a[p] into the heap.
{
    for(int i=2*p; i<=r; i*=2)
    {
        if(i==r)
        {
            if (a[p]>a[i]) return;
        }
        else
        {
            if (a[p]>a[i] && a[p]>a[i+1]) return;
            if (a[i]<a[i+1]) i++;
        }
        swap(a[p], a[i]);
        p=i;
    }
}

void HeapSort(int a[], int r)
{
    for(int i=r/2; i>=1; i--)
        HeapAdjust(a, i, r);
    for(int i=r; i>1; i--)
    {
        swap(a[1], a[i]);
        HeapAdjust(a, 1, i-1);
    }
}

void Merge(int a[], int l, int m, int r)
{
    int *t=new int[r-l+2];
    int k=1, p=l, q=m+1;
    while(k<=r-l+1 && p<=m && q<=r)
        if (a[p]<a[q])
        {
            t[k]=a[p];
            k++;
            p++;
        }
        else
        {
            t[k]=a[q];
            k++;
            q++;
        }
    while(p<=m)
    {
        t[k]=a[p];
        k++;
        p++;
    }
    while(q<=r)
    {
        t[k]=a[q];
        k++;
        q++;
    }
    for(int i=l; i<=r; i++) a[i]=t[i-l+1];
    delete[] t;
}

void MergeSort(int a[], int l, int r)
{
    if (l>=r) return;
    int m=(l+r)/2;
    MergeSort(a, l, m);
    MergeSort(a, m+1, r);
    Merge(a, l, m, r);
    return;
}