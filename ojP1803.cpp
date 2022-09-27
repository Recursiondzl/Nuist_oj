/*
 * @Description: To iterate is human, to recurse divine.
 * @Autor: Recursion
 * @Date: 2022-06-08 09:52:57
 * @LastEditTime: 2022-06-08 11:15:27
 */
#include <bits/stdc++.h>

char p[1000005], t[1000005];
int len1, len2;
int next[1000005], next2[1000005];
int ans;
void do_next()
{
    next[0] = 0;
    int i = 1;
    int len = 0;

    while (i < len2)
    {
        if (t[i] == t[len])
            next[i++] = ++len;
        else
        {
            if (len > 0)
                len = next[len - 1];
            else
                next[i++] = len;
        }
    }
}

void kmp()
{
    int i = 0, j = 0;
    next2[0] = -1;
    
    for (int i = 1; i < len2; i++)
        next2[i] = next[i - 1];
    
    while (i < len1)
    {
        if (j == len2 - 1 && p[i] == t[j])
        {
            ans++;
            j = next2[j];
            if (j == -1)
                j++;
        }
        if (p[i] == t[j])
        {
            j++;
            i++;
        }
        else
        {
            j = next2[j];
            if (j == -1)
            {
                i++;
                j++;
            }
        }
    }
}

int main()
{
    scanf("%s%s", p, t);
    len1 = strlen(p);
    len2 = strlen(t);

    do_next();

    kmp();

    printf("%d\n",ans);

    return 0;
}