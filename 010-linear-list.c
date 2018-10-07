// Linear List

ADT List 
{
    InitList(&L)
    DestroyList(&L)
    ClearList(&L)
    ListEmpty(L)
    ListLength(L)
    GetElem(L, i, &e)
    LocateElem(L, e, compare())
    PrevElem(L, cur_e, &prev_e)
    NextElem(L, cur_e, &next_e)
    ListInsert(&L, i, e)
    ListDelete(&L, i, &e)
    ListTraverse(L, visit())
};

// Algorithm 2.1
// Union of 2 sets
void Union(List &La, List Lb)
{
    La_length=ListLength(La);
    Lb_length=Listlength(Lb);
    for(i=1;i<=Lb_length;i++)
    {
        GetElem(La, i, e);
        if (!LocateElem(La, e, equal))
            ListInsert(La, ++La_length, e)
    }
}

// Algorithm 2.2
// Merge 2 ordered lists
void MergeList(List La, List Lb, List &Lc)
{
    InitList(Lc)
    i=1; j=1; k=0;
    La_length=ListLength(La);
    Lb_length=Listlength(Lb);
    while ((i<=La_length) && (j<=Lb_length))
    {
        GetElem(La, i, ai);
        GetElem(Lb, j, bj);
        if (ai<=bj)
        {
            ListInsert(Lc, ++k, ai);
            i++;
        }
        else {
            ListInsert(Lc, ++k, bj);
            j++;
        }
    }
    while (i<=La_length)
    {
        GetElem(La, i++, ai);
        ListInsert(Lc, ++k, ai)
    }
    while (i<=Lb_length)
    {
        GetElem(Lb, i++, bj);
        ListInsert(Lc, ++k, bj)
    }
}

// SqList
# define LIST_INIT_SIZE 100
# define LISTINCREMENT 10
struct{
    ElemType* elem;
    int length;
    int listsize;
}

// Algorithm 2.3
// Initialize a sequence list
Status Initlist_Sq(Sqlist &L)
{
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!L.elem) exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

// Algorithm 2.4
// Insert an element to an ordered sequence list, before the ith element
Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    if (i<1 || i>L.length) 
        return ERROR;
    if (L.length<=L.listsize)
    {
        newbase=(ElemType*)realloc(L.elem, (L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if (!newbase) return OVERFLOW;
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    q=&(L.elem[i-1]);
    for(p=&(L.elem[L.length-1]);p>=q;p--)
        *(p+1)=*p;
    *q=e;
    L.length++;
    return OK;
}

// Algorithm 2.5
// Delete the ith element in a sequence list and return to e
Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    if (i<1 or i>L.length) return ERROR;
    p=&(L.elem[i-1]);
    *p=e;
    for(q=p;q<=&(L.elem[L.length-1]);q++)
        *q=*(q+1);
    L.length--;
    return OK;
}

// Algorithm 2.6
// Locate the first element that satisfies compare()
int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    p=L.elem;
    for(i=0;i<=L.length;i++)
        if((*compare)(*p++,e)) return i;
    return 0;
}

// Algorithm 2.7
// Merge 2 ordered squence lists
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
{
    pa=La.elem;
    pb=Lb.elem;
    Lc.listsize=Lc.length=Lb.length+La.length;
    pc=Lc.elem=(ElemType*)malloc(Lc.listsize, sizeof(ElemType)));
    while(pa<=La.elem+La.length-1 && pb<=Lb.elem+Lb.length-1)
        if (*pa>=*pb)
            *pc++=*pa++;
        else
            *pc++=*pb++;
    while(pa<=La.elem-1)
        *pc++=*pa++;
    while(pb<=Lb.elem-1)
        *pc++=*pb++;
}

// Linked List

// Single Linked List
struct LNode
{
    ElemType data;
    struct LNode *next;
}
LNode * LinkList;

// Algorithm 2.8
// Get the ith element in a single linked list
Status GetElem_L(LinkList L, int i, ElemType &e)
{
    p=L;
    j=0;
    while (p && j<i)
    {
        p=p->next;
        j++;
    }
    if (!p || j>i) return ERROR;
    e=p->data;
    return OK;
}

// Algorithm 2.9
// Insert an element before the ith element in a linked list
Status ListInsert_L(LinkList &L, int i, ElemType e)
{
    p=L;
    j=0;
    while(p && j<i-1)
    {
        p=p->next;
        j++;
    }
    if (!p || j>i-1) return ERROR;
    s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

// Algorithm 2.10
// Delete the ith element and return to e
Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    p=L;
    j=0;
    while(p && j<i-1)
    {
        p=p->next;
        j++;
    }
    if (!p || j>i) return ERROR;
    p->next=(p=>next)->next;
    e=(p->next)->data;
    free(p->next);
    return OK;
}

// Algorithm 2.11
// Create a linked list
void CreateList_L(LinkList &L, int n)
{
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    for (i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        scanf(&p->data);
        p->next=L->next;
        L->next=p;
    }
}

// Algorithm 2.12
// Merge two ordered linked lists
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    pa=La->next;
    pb=Lb->next;
    Lc=La;
    pc=Lc;
    while (pa&&pb)
        if (pa->data>pb->data)
        {
            pc->next=pa;
            pc=pc->next;
            pa=pa->next;  
        }
        else
        {
            pc->next=pb;
            pc=pc->next;
            pb=pb->next;
        }
    pc->next=pa?pa:pb;
    free(Lb);
    return;
}

// Static Linklist
#define MAXSIZE 1000
struct
{
    ElemType data;
    int cur;    
}component, SLinkList[MAXSIZE];

// Algorithm 2.13
// Find the ith element in a static linklist
int LocateElem_SL(SLinkList S, ElemType e)
{
    i=S[0].cur;
    while(i && S[i].data!=e) i=S[i].cur;
    return i;
}

// Algorithm 2.14
// Initialize a static linked list
void InitSpace_SL(SLinkList &space)
{
    for(i=0;i<MAXSIZE-1;i++)
        space[i].cur=i+1;
    space[MAXSIZE-1].cur=0;
}

// Algorithm 2.15
// Return the adress of the first available empty element
int Malloc_SL(SLinkList &space)
{
    i=space[0].cur;
    if (space[0].cur) space[0].cur=space[i].cur;
    return i;
}

// Algorithm 2.16
// Free the kth element
void Free_SL(SLinkList &space, int k)
{
    space[k].cur=space[0].cur;
    space[0].cur=k;
}

// Algorithm 2.17
// Calculate the difference of two sets A and B
// (A-B)∪(B-A)
void difference(SLinkList &space, int &S)
{
    InitSpace_SL(space);
    S=Malloc_SL(space);
    r=S;
    scanf(m,n); //Element number of A and B
    for (j=1;j<=m;j++)
    {
        i=Malloc_SL(space);
        scanf(space[i].data);
        space[r].cur=i;
        r=i;
    }
    space[r].cur=0;
    for (j=1;j<=n;j++)
    {
        scanf(b);
        p=S;
        k=space[S].cur;
        while (k!=space[r].cur && space[k].data!=b)
        {
            p=k;
            k=space[k].cur;
        }
        if (k==space[r].cur)
        {
            
        }
    }
}
