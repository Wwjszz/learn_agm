#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;
int a[N], dp[N];

int main()
{

    scanf("%d", &n);

    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int j;
    for (i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (j = i - 1; j >= 1; j--)
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
    }

    int res = 0;
    for (i = 1; i <= n; i++)
        res = max(dp[i], res);

    printf("%d\n", res);
    return 0;
}