#include <iostream>

using namespace std;

const int N = 1010, mod = 1e9 + 7;
int n;
int dp[N][N];

int main()
{
    scanf("%d", &n);

    int i, j;
    dp[1][1] = 1;
    for (i = 2; i <= n; i++)
        for (j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % mod;

    int res = 0;
    for (i = 1; i <= n; i++)
        res = (res + dp[n][i]) % mod;

    printf("%d\n", res);

    return 0;
}