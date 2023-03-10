#include <iostream>

using namespace std;

const int N = 100010;
int q[N], temp[N];
long long ans;

void merge_sort(int l, int r, int q[])
{
    if (l >= r)
        return;

    int mid = l + (r - l >> 1);

    merge_sort(l, mid, q);
    merge_sort(mid + 1, r, q);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            temp[k++] = q[i++];
        else
        {
            temp[k++] = q[j++];
            ans += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = q[i++];
    while (j <= r)
        temp[k++] = q[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        q[i] = temp[k];
}

int main()
{
    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &q[i]);

    merge_sort(0, n - 1, q);

    printf("%d\n", ans);

    return 0;
}