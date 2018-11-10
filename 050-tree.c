// Tree

#include "dsdef.h"

// Binary Tree

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// Algorithm 6.1
Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType e))
{
    if (T)
    {
        if (Visit(T->data))
            if (PreOrderTraverse(T->lchild),Visit)
                if (PreOrderTraverse(T->rchild),Visit)
                    return OK;
        return ERROR;
    }
    else
        return OK;
}

// Algorithm 6.2
// Inorder traversing in stack 1
Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType e))
{
    InitStack(S);
    Push(S,T);
    while (!StackEmpty(S))
    {
        while (GetTop(S,p)&&p)
            Push(S, p->lchild); 
        Pop(S,p);
        if (!InitStack(S))
        {
            Pop(S,p);
            if(!Visit(p->data)) return ERROR;
            Push(S,p->rchild);
        }
    }
    return OK;
}

// Algorithm 6.3
// Inorder traversing in stack 2
Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType e))
{
    InitStack(S);
    p=T;
    while( p || !StackEmpty(S))
    {
        if (p) 
        {
            Push(S,p);
            p=p->lchild;
        }
        else
        {
            Pop(S,p);
            if(!Visit(p->data)) return ERROR;
            p=p->rchild;
        }
    }
    return OK;
}

// Algorithm 6.4
// PreOrder
Status CreateBiTree(&T)
{
    scanf(&ch);
    if (ch=='') 
        T=NULL;
    else
    {
        if (!(T=(BiTNode*)malloc(sizeof(BiTNode)))) return OVERFLOW;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

// Algorithm Extra
// Calculate the depth of a binary tree by postorder traversing
int depth(BiTree T)
{
    if (T)
    {
        ldepth=depth(T->lchild);
        rdepth=depth(T->rchild);
        depth= 1+(ldepth>rdepth? ldepth : rdepth);
    }
    else
        depth=0;
    return depth;
}

// Algorithm Extra
// Copy a binary tree
BiTNode *CreatBiTNode(TElemType e, BiTree ltree, BiTree rtree)
{
    if (!(T=(BiTNode*)malloc(sizeof(BiTNode))))
        return OVERFLOW;
    T->data=e;
    T->lchild=ltree;
    T->rchild=rtree;
    return T;
}
BiTree CopyBiTree(BiTree T)
{
    if(!T) return NULL;
    if (T->lchild) 
        lp=CopyBiTree(T->lchild);
    else
        lp=NULL;
    if (T->rchild)
        rp=CopyBiTree(T->rchild);
    else 
        rp=NULL;
    newT=CreatBiTNode(T->data, lp, rp);
    return newT;
}

// Algorithm Extra
void BreadthFirstTraverse(BiTree T, Status (*Visit)(TElemType e))
{
    InitQueue(Q);
    if (!T) return;
    EnQueue(Q, T);
    for (;;)
    {
        DeQueue(Q, a);
        Visit(a->data);
        if (a->lchild) EnQueue(Q, a->lchild);
        if (a->rchild) EnQueue(Q, a->rchild);
        if (QueueEmpty(Q)) break;
    }
}

// Algorithm Extra
// Reconstruct a tree by the preoeder and inorder traverse sequence
BiTree ReconstructTree(string pre, string in)
{
    root=pre[0];
    if (!root) return NULL; 
    if (!(T=(BiTree*)malloc(sizeof(BiTree)))) return OVERFLOW;
    T->data=root;
    pos=Index(in, root);
    T->lchild=ReconstructTree(pre[1..pos],in[0..pos-1]);
    T->rchild=ReconstructTree(pre[pos+1..pre.length-1],in[pos+1..in.legnth-1]);
    return T;
}

// Threaded Binary Tree
typedef enum PointerTag {Link, Thread};
typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag, RTag;
}BiThrNode, *BithrTree;

// Algorithm 6.5
Status InOrderTraverse_Thr(BiThrNode T, Status (*Visit)(TElemType e))
{
    p=T->lchild; //T->lchild is the root according to the threading algorithm
    while (p!=T)
    {
        while (p->LTag==Link)
            p=p->lchild; // The leftest node
        if (!Visit(p->data)) return ERROR;
        while (p->RTag==Thread && p->rchild!=T)
        {
            p=p->rchild;
            Visit(p->data);
        }
        p=p->rchild;
    }
    return OK;
}

// Algorithm 6.6
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
    if (!(Thrt=(BithrTree)malloc(sizeof(BiThrNode)))) return OVERFLOW;
    Thrt->LTag=Link;
    Thrt->RTag=Thread;
    Thrt->rchild=Thrt;
    if (!T) Thrt->lchild=Thrt;
    else
    {
        Thrt->lchild=T;
        pre=Thrt;
        InThreading(T);
        pre->RTag=Thread;
        pre->rchild=Thrt;
        Thrt->rchild=pre;
    }
    return OK;
}

// Algorithm 6.7
Status InThreading(BiThrTree p)
{
    InThreading(p->lchild);
    if (!p->lchild)
    {
        p->LTag=Thread;
        p->lchild=pre;
    }
    if (!pre->rchild)
    {
        pre->RTag=Thread;
        pre->rchild=p;
    }
    pre=p;
    InThreading(p->rchild);
}

// Huffman Tree