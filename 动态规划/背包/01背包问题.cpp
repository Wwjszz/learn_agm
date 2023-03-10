#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int dp[N];

int main()
{

    cin >> n >> m;

    int i;
    for (i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    int j;
    for (i = 1; i <= n; i++)
        for (j = m; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

    cout << dp[m] << endl;

    return 0;
}