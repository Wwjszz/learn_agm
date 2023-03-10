#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 310;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, m;
int a[N][N];
int dp[N][N];

int dfs(int x, int y)
{
    int &v = dp[x][y];
    if (v != -1)
        return v;

    v = 1;

    int i;
    for (i = 0; i < 4; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx >= 0 && ty >= 0 && tx < n && ty < m && a[x][y] > a[tx][ty])
            v = max(v, dfs(tx, ty) + 1);
    }

    return v;
}

int main()
{
    scanf("%d%d", &n, &m);

    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            ans = max(ans, dfs(i, j));

    printf("%d\n", ans);

    return 0;
}