#include <iostream>
#include <algorithm>

using namespace std;

const int N = 310;
int n;
int a[N];
int dp[N][N];

int main()
{

    scanf("%d", &n);

    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (i = 1; i <= n; i++)
        a[i] += a[i - 1];

    int j, len, k;
    for (len = 2; len <= n; len++)
        for (i = 1; i + len - 1 <= n; i++)
        {
            j = i + len - 1;
            dp[i][j] = 1e8;
            for (k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1]);
        }

    printf("%d\n", dp[1][n]);

    return 0;
}