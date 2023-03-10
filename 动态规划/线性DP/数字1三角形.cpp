#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 1e9;

int n;
int a[N][N];
int f[N][N];

int main()
{

    scanf("%d", &n);

    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
            f[i][j] = -INF;

    f[1][1] = a[1][1];
    for (i = 2; i <= n; i++)
        for (j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j] + a[i][j], f[i - 1][j - 1] + a[i][j]);

    int res = -INF;
    for (i = 1; i <= n; i++)
        res = max(res, f[n][i]);

    printf("%d\n", res);
    return 0;
}