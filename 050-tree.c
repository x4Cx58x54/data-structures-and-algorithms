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
