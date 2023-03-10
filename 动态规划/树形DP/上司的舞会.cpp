#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 6010;
int n;
int h[N], e[N], ne[N], idx;
int ha[N];
bool fa[N];
int dp[N][2];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    dp[u][1] = ha[u];

    int i;
    for (i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);

        dp[u][1] += dp[j][0];
        dp[u][0] += max(dp[j][0], dp[j][1]);
    }
}

int main()
{

    scanf("%d", &n);

    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", &ha[i]);

    memset(h, -1, sizeof h);

    for (i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(b, a);
        fa[a] = 1;
    }

    int root = 1;
    while (fa[root])
        root++;

    dfs(root);

    printf("%d\n", max(dp[root][0], dp[root][1]));

    return 0;
}