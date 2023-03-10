#include <iostream>
#include <algorithm>

using namespace std;
const int N = 100010;
int n;
int a[N];

int main()
{

    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);

    long long res = 0;
    for (i = n - 1; i >= 0; i--)
        res += a[i] * (n - 1 - i);

    printf("%lld\n", res);

    return 0;
}