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

// Algorithm 3.1
// Positional system conversion
void conversion()
{
    InitStack(S);
    scanf("%d", N);
    while (N)
    {
        Push(S, N%8);
        N/=8;
    }
    while (!StackEmpty(S))
    {
        Pop(S,e);
        printf("%d",e);
    }
}

// Algorithm 3.2
void LineEdit()
{
    InitStack(S);
    ch=getchar();
    while (ch!=EOF)
    {
        while (ch!=EOF && ch!='\n')
        {
            switch(ch)
            {
                case '#': Pop (S,c); break;
                case '@': ClearStack(S); break;
                default: Push(S,ch); break; 
            }
            ch=getchar();
        }
        ClearStack(S);
        if (ch!=EOF) ch=getchar();
    }
    DestroyStack(S);
}

// Algorithm 3.3
// Maze
struct
{
    int ord;
    PosType seat;
    int di;
}SElemType;

Status MazePath(MazeType maze, PosType start, PosType end)
{
    InitStack(S);
    curpos=start;
    curstep=1;
    do
    {
        if (Pass(curpos))  // Neither blocked or footprinted
        {
            FootPrint(curpos);
            e=(curstep, curpos, 1);
            Push(S,e);
            if (curpos==end) return TRUE;
            curpos=NextPos(curpos,1);
            curstep++;
        }
        else
        {
            if (!StackEmpty(S))
            {
                Pop(S,e);
                while (e.di==4 && !StackEmpty(S))
                {
                    MarkPrint(e.seat); // Mark as unavailable
                    Pop(S,e);
                }
                if (di<4)
                {
                    e.di++;
                    Push(S,e);
                    curpos=NextPos(e.seat, e.di);
                }
            }
        }
    }while(!StackEmpty(S));
    return FALSE;
}

// Algorithm 3.4
OperandType EvaluateExpression()
{
    InitStack (OPTR);
    Push(OPTR, '#');
    InitStack (OPND);
    c=getchar();
}