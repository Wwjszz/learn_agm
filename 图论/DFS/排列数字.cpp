#include <iostream>

using namespace std;

const int N = 10;

int a[N];
int n;

void dfs(int u, int state)
{
    if (u == n + 1)
    {
        int i;
        for (i = 1; i <= n; i++)
            printf("%d ", a[i]);
        puts("");
        return;
    }
    int i;
    for (i = 1; i <= n; i++)
        if (!(state & (1 << i)))
        {
            a[u] = i;
            dfs(u + 1, state + (1 << i));
        }
}

int main()
{
    scanf("%d", &n);

    dfs(1, 0);

    return 0;
}