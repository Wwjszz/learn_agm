#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

int main()
{
    scanf("%d%d", &n, &m);
    int i, j;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);

    while (i < n && j < m)
    {
        if (a[i] == b[j])
            i++;
        j++;
    }

    if (i == n)
        puts("Yes");
    else
        puts("No");

    return 0;
}