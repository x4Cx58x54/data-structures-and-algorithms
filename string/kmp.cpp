/*
    Knuth-Morris-Pratt Algorithm
*/

#include <stdio.h>
#include <string>
void kmp(std::string text, std::string pattern)
{
    int pmt[pattern.length()];
    for(int i = 1, j = 0; i < pattern.length(); i++)
    {
        while(pattern[i] != pattern[j] && j > 0)
            j = pmt[j-1];
        if (pattern[i] == pattern[j])
            j++;
        pmt[i] = j;
    }
    for(int i = 0, j = 0; i < text.length(); i++)
    {
        while(text[i] != pattern[j] && j > 0)
            j = pmt[j-1];
        if (text[i] == pattern[j])
            j++;
        if(j == pattern.length())
        {
            printf("%d\n", i-j+1);
            j = pmt[j-1];
        }
    }
}
