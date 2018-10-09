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
struct Stack
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
struct SqStack
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack &S);
Status DestroyStack(SqStack &S);
Status ClearStack(SqStack &S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, SElemType &e);
Status Push(SqStack &S, SElemType e);
Status Pop(SqStack &S, SElemType &e);
Status StackTraverse(SqStack S, Status(*visit)());

// Fundamental Operations
Status InitStack(SqStack &S)
{
    S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if (!S.base) return OVERFLOW;
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

Status GetTop(SqStack S, SElemType &e)
{
    if (S.top==S.base) return ERROR;
    e=*(S.top-1)
    return OK;
}

Status Push(SqStack &S, SElemType e)
{
    if (S.top-S.base>=S.stacksize)
    {
        S.base=(SElemType*)realloc(S.base, (S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if (!S.base) return OVERFLOW;
        S.top=S.top+STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
    if (S.top==S.base) return ERROR;
    e=*--S.top;
    return OK;
}