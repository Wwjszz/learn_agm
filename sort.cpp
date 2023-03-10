#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N];

void quick_sort(int l, int r, int q[])
{

    if (l >= r)
        return;

    int i = l - 1, j = r + 1, x = q[l + (r - l >> 1)];
    while (i < j)
    {

        while (q[++i] < x)
            ;

        while (q[--j] > x)
            ;

        if (i < j)
            swap(q[i], q[j]);

        for (int z = l; z <= r; z++)
            printf("%d ", q[z]);
        printf("\n");
        printf("i:%d j:%d\n", i, j);
    }

    quick_sort(l, j, q); // 至于为什么是 j 为边界，一般i和j是相等的
    // 10
    // 49 59 88 37 98 97 68 54 31 3
    // 用这个例子能看出 i是会大于j的，当极端情况时，用i会导致无法减少规模进而死循环（这个例子），也可能会导致错误（如果q[x]排序中成第一个并且后面的数都大于他）
    // 快排目的是减小规模，但是如果不用j，遇到极端情况，如
    quick_sort(j + 1, r, q);
}

int main()
{
    int n;
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &q[i]);

    quick_sort(0, n - 1, q);

    for (i = 0; i < n; i++)
        printf("%d ", q[i]);

    return 0;
}