#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m;
char a[N], b[N];
int dp[N][N];

int main()
{

    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);

    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }

    printf("%d\n", dp[n][m]);

    return 0;
}