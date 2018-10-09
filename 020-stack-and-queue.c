// Stack and Queue

ADT Stack
{
    InitStack(&S);
    DestroyStack(&S);
    ClearStack(&S);
    StackEmpty(S);
    StackLength(S);
    GetTop(S, &e);
    Push(&S, e);
    Pop(&S, &e);
    StackTraverse(S,visit());
}

// Sequence stack
typedef struct Stack
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;