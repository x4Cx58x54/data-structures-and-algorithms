// Array

// Sparse Matrix

// Triple
#define MAXSIZE 12500
struct
{
    int i,j;
    ELemType e;
}Triple;
struct 
{
    Triple data[MAXSIZE+1];
    int mu,nu,tu;
}TSMatrix;

// Algorithm 5.1
Status TransposeSMatrix(TSMatrix M, TSMatrix &T)
{
    T.mu=M.nu;
    T.nu=N.mu;
    T.tu=M.tu;
    if (T.tu)
    {
        q=1;
        for (col=1;col<=M.nu;col++)
            for (p=1;p<=M.tu;)
                if (M.data[p].j==col)
                {
                    T.data[q].i=M.data[p].j;
                    T.data[q].j=M.data[p].i;
                    T.data[q].e=M.data[p].e;
                    q++;
                }
    }
    return OK;
}

// Algorithm 5.2
Status FastTransposeSMatrix(TSMatrix M, TSMatrix &T)
{
    if(M.tu)
    {
        // num[col]: number of nonzero elements in the column
        for(col=1;col<=M.nu;col++) 
            num[col]=0;
        for(t=1;t<=M.tu;t++) 
            num[M.data[t].j]++;

        // cpot[col]: the position (T.data[pos]) of the first data in the col^th element in M
        cpot[1]=1;
        for(col=2;col<=M.nu;col++)
            cpot[col]=cpot[col-1]+num[col-1];

        T.mu=M.nu;
        T.nu=M.mu;
        T.tu=M.tu;
        for(t=1;t<=M.tu;t++)
        {
            q=cpot[M.data[t].j];
            T.data[q].i=M.data[p].j;
            T.data[q].j=M.data[p].i;
            T.data[q].e=M.data[p].e;
            cpot[M.data[t].j]++;
        }
    }
    return OK;
}

// Algorithm 5.3
struct
{
    Triple data[MAXSIZE+1];
    int rpos[MAXRC+1]; //the position (data[pos]) of the first nonzero element in a row
    int nu, mu, tu;
}RLSMatrix;

Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q)
{
    if (M.nu!=N.nu) return ERROR;
    Q.mu=M.mu;
    Q.nu=N.nu;
    Q.tu=0;
    if (M.tu!=0 && N.tu!=0)
    {
        for(arow=1;arow<=M.mu;arow++)
        {
            ctemp[]=0;
            Q.rpos[arow]=Q.tu+1;
            if (arow<M.mu) tp=M.rpos[arow+1];
            else tp=M.tu+1;
            
        }
    }
}