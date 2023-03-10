#include <iostream>

using namespace std;

const int N = 100010;
int k;
int q[N];

int quick_sort(int q[], int l, int r, int k)
{
    if (l >= r)
        return q[l];

    int i = l - 1, j = r + 1, x = q[l + (r - l >> 1)];
    while (i < j)
    {
        while (q[++i] < x)
            ;
        while (q[--j] > x)
            ;
        if (i < j)
            swap(q[i], q[j]);
    }

    if (j - l + 1 >= k)
        return quick_sort(q, l, j, k);
    else
        return quick_sort(q, j + 1, r, k - (j - l + 1));
}

int main()
{
    int n, k, i;
    scanf("%d%d", &n, &k);

    for (i = 0; i < n; i++)
        scanf("%d", &q[i]);

    printf("%d\n", quick_sort(q, 0, n - 1, k));

    return 0;
}