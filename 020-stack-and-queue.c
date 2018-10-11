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
    InitStack(OPTR);
    Push(OPTR,'#');
    InitStack(OPND);
    c=getchar();
    while (c!='#' || GetTop(OPTR,'#')!='#')
    {
        if (IsOperand)
        {
            Push(OPND,c);
            c=getchar();
        }
        else
            switch(Precede(GetTop(OPND), c))
            {
                case '<':
                    Push(OPTR,c);
                    c=getchar();
                    break;
                case '=':
                    Pop(OPTR,x);
                    c=getchar();
                    break;
                case '>':
                    Pop(OPTR, theta);
                    Pop(OPND, b);
                    Pop(OPND, a);
                    Push(OPND, Operate(a, theta, b));
                    break;
            }
    }
    return GetTop(OPND);
}

// Algorithm 3.5
void hanoi(int n, char x, char y, char z)
{
    if (n==1)
        move(x,1,z);
    else
    {
        hanoi(n-1,x,z,y);
        move(x,n,z);
        hanoi(n-1,y,x,z);
    }
}

// Queue

// Linked Queue
struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q);
Status ClearQueue(LinkQueue &Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, QElemType &e);
Status EnQueue(LinkQueue &Q, QElemType e);
Status DeQueue(LinkQueue &Q, QElemType &e);
Status QueueTraverse(LinkQueue Q, visit());

Status InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    if (!Q.front) return OVERFLOW;
    Q.front->next=NULL;
    return OK;
}

Status DestroyQueue(LinkQueue &Q)
{
    while (Q.front)
    {
        Q.rear=Q.front->next;
        free(Q.front);
        Q.front=Q.rear;
    }
    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e)
{
    p=(QueuePtr)malloc(sizeof(QNode));
    if (!p) return OVERFLOW;
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
    if (Q.front==Q.rear) return ERROR;
    p=Q.front->next;
    e=p.data;
    Q.front=p->next;
    if (Q.rear=p)
        Q.rear=Q.front;
    free(p);
    return OK;
}