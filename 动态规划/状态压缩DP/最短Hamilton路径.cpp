#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << 20;
int n;
int w[N][N];
int dp[M][N]; // dp[i][j] 表示从0开始，终点为j，经过的节点为M所反映状态的节点集合(除了0、j)

int main()
{
    scanf("%d", &n);

    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &w[i][j]);

    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0; // 如果不是从0开始，则为无穷大。

    int k;
    int st = 1 << n;
    for (i = 0; i < st; i++)
        for (j = 0; j < n; j++)
            if (i >> j & 1)
                for (k = 0; k < n; k++)
                    if (i >> k & 1 && k != j)
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + w[k][j]);

    printf("%d\n", dp[st - 1][n - 1]);

    return 0;
}