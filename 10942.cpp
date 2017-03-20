#include <cstdio>
#include <memory.h>
 
int c[2001];
int d[2001][2001];
 
int go(int i, int j){
    if (d[i][j] != -1) return d[i][j];
    if (i == j) return  1;
    else if (i + 1 == j){
        if (c[i] == c[j]) return  1;
        else return 0;
    }
    if (c[i] != c[j]) return d[i][j] = 0;
    else return d[i][j] = go(i + 1, j - 1);
}
 
int main()
{
    memset(d, -1, sizeof(d));
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    scanf("%d", &m);
 
    for (int test_case = 1; test_case <= m; test_case++){
        int s, e;
        scanf("%d %d", &s,&e);
        printf("%d\n", go(s, e));
    }
    return 0;
}