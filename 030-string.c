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