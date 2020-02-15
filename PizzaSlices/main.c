#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long n,a[20000],visited[20000],temporary[20000],finally[20000],globaldep;
long long c,mindiff;
int pd;
int printed;

void print(long dep, long* d)
{
    for (long j=0;j <= dep; ++j) printf("%ld ",d[j]);
    printf("\n");
}
void copya2b(long* a, long* b, long dep){
    for (long j=0;j <= dep; ++j) b[j] = a[j];
}

void dfs(long dep)
{
    long r;
    if (pd == 1) return;
    for (r = 0;r < n; ++r)
      if (!visited[r] && c - a[r] >= 0){
        if (pd == 1) return;
        c -= a[r];
        temporary[dep] = r;
        visited[r] = 1;
        if (c == 0) {
            printf("%ld\n",dep);
            print(dep,temporary);
            pd = 1;
            printed = 1;
        }

        if (c > 0) dfs(dep + 1);

        if (pd == 1) return;
        c += a[r];
        if (c < mindiff) {
            mindiff = c;
            copya2b(temporary,finally,dep);
            globaldep = dep;
        }
        visited[r] = 0;
      }
}

int main()
{
    printed = 0;
    scanf("%lld %ld",&c,&n);
    for (long i = 0;i < n; ++i) scanf("%ld",&a[i]);
    memset(temporary,0,sizeof(temporary));
    memset(visited,0,sizeof(visited));
    mindiff = c;
    pd = 0;
    dfs(0);
    if (!printed){
        printf("%ld\n",globaldep+1);
        print(globaldep,finally);
    }
    return 0;
}
