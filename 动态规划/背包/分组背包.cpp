#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];
int dp[N];

int main()
{

    cin >> n >> m;
    int i;
    for (i = 1; i <= n; i++)
    {
        cin >> s[i];
        int j;
        for (j = 0; j < s[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }

    int j, k;
    for (i = 1; i <= n; i++)
        for (j = m; j >= 0; j--)
            for (k = 0; k < s[i]; k++)
                if (v[i][k] <= j)
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);

    cout << dp[m] << endl;

    return 0;
}