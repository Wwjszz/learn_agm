#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N], w[N], s[N];
int dp[N][N];

int main()
{
    cin >> n >> m;

    int i;
    for (i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];

    int j, k;
    for (i = 1; i <= n; i++)
        for (j = 0; j <= m; j++)
            for (k = 0; k <= s[i] && k * v[i] <= j; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i] * k] + k * w[i]);

    cout << dp[n][m] << endl;

    return 0;
}