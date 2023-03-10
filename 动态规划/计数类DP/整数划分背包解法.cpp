#include <iostream>

using namespace std;
const int N = 1010, mod = 1e9 + 7;
int n;
int dp[N];

int main()
{
    scanf("%d", &n);

    int i, j;
    dp[0] = 1;
    for (i = 1; i <= n; i++)
        for (j = i; j <= n; j++)
            dp[j] = (dp[j] + dp[j - i]) % mod;

    printf("%d\n", dp[n]);

    return 0;
}
