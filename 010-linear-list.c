// Linear List

ADT List {
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
void Union(List &La, List Lb){
    La_length=ListLength(La);
    Lb_length=Listlength(Lb);
    for(i=1;i<=Lb_length;i++){
        GetElem(La, i, e);
        if (!LocateElem(La, e, equal))
            ListInsert(La, ++La_length, e)
    }
}

// Algorithm 2.2
// Merge 2 ordered lists
void MergeList(List La, List Lb, List &Lc){
    InitList(Lc)
    i=1; j=1; k=0;
    La_length=ListLength(La);
    Lb_length=Listlength(Lb);
    while ((i<=La_length) && (j<=Lb_length)){
        GetElem(La, i, ai);
        GetElem(Lb, j, bj);
        if (ai<=bj){
            ListInsert(Lc, ++k, ai);
            i++;
        }
        else {
            ListInsert(Lc, ++k, bj);
            j++;
        }
    }
    while (i<=La_length){
        GetElem(La, i++, ai);
        ListInsert(Lc, ++k, ai)
    }
    while (i<=Lb_length){
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
Status Initlist_Sq(Sqlist &L){
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!L.elem) exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}



