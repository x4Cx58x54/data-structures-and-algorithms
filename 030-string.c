// String

ADT String
{
    StrAssign(&T, chars);
    StrCopy(&T, S);
    StrEmpty(S);
    StrCompare(S, T);
    StrLength(S);
    ClearString(S);
    Concat(&T, S1, S2);
    SubString(&Sub, S, pos, len);
    Index(S, T, pos);
    Replace(&S, T, V);
    StrInsert(&S, pos T);
    StrDelete(&S, pos, len);
    DestroyString(&S);
}

// Minimum Operation Set
// StrAssign, StrCompare, StrLength, Concat, SubString

// Algorithm 4.1
int Index(String S, String T, int pos)
{
    if (pos>0)
    {
        n=StrLength(S);
        m=StrLength(T);
        i=pos;
        while(i<n-m+1);
        {
            SubString(sub, S, i, m);
            if(StrCompare(sub, T)!=0) i++;
            else return i;
        }
    }
    return 0;
}

#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN+1];

// Algorithm 4.2
Status Concat(SString &T, SString S1, SString S2)
{
    if (S1[0]+S2[0]<=MAXSTRLEN)
    {
        T[1..S1[0]]=S1[1..S1[0]];
        T[S1[0]+1..S1[0]+S2[0]]=S2[1..S2[0]];
        T[0]=S1[0]+S2[0];
        uncut=TRUE;
    }
    else if (S1[0]<MAXSTRLEN)
    {
        T[1..S1[0]]=S1[1..S1[0]];
        T[S1[0]+1..MAXSTRLEN]=S2[1..MAXSTRLEN-S1[0]];
        T[0]=MAXSTRLEN;
        uncut=FALSE;
    }
    else
    {
        T[0..MAXSTRLEN]=S1[0..MAXSTRLEN];
        uncut=FALSE;
    }
    return uncut;
} 

// Algorithm 4.3
Status SubString(SString &Sub, SString S, int pos,int len)
{
    if (pos<1 || pos>S[0] || len<0 || len>S[0]-pos+1)
        return ERROR;
    Sub[1..len]=S[pos..pos+len-1];
    Sub[0]=len;
    return OK;
}

// Algorithm 4.4
struct
{
    char *ch;
    int length;
}HString;

Status StrInsert(HString &S, int pos, HString T)
{
    if (pos<1 || pos>S.length+1) return ERROR;
    if (T.legnth)
        {
            if (!(S.ch=(char*)realloc(S.ch,(S.length+T.length)*sizeof(char))))
                return OVERFLOW;
            for(i=S.length-1;i>pos;i--)
                S.ch[i+T.lengh]=S.ch[i];
            S.ch[pos-1..pos+T.length-2]=T.ch[0..T.length-1];
            S.length+=T.length;
        }
    return OK;
}

// ADT HString
Status StrAssign(HString &T, char *chars)
{
    if (T.ch) free(T.ch);
    for(i=0,c=chars;*c;i++,c++);
    if(!i)
    {
        T.ch=NULL;
        T.length=0;
    }
    else
    {
        if (!(T.ch=(char*)malloc(i*sizeof(char))))
            return OVERFLOW;
        T.ch[0..i-1]=chars[0..i-1];
        T.length=i;
    }
    return OK;
}

int StrLength(HString)
{
    return S.length;
}

int StrCompare(HString S, HString T)
{
    for(i=0;i<S.length && i<T.length;i++)
        if (S.ch[i]!=T.ch[i]) return S.ch[i]-T.ch[i]
    return S.length-T.length;
}

Status ClearString(HString &S)
{
    if (S.ch)
    {
        free(S.ch);
        S.ch=NULL;
    }
    S.length=0;
    return OK;
}
