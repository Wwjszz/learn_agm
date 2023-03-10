#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], s[N];

int main()
{
    scanf("%d%d", &n, &m);
    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    int l, r;
    while (m--)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}