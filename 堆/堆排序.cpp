#include <iostream>
#include <algorithm>

// 堆中的父节点一定比它的子节点小，对于每个节点都是如此，所以堆的根是最小的。
// 在down时，必须保证其子节点以及其之后的所有子节点都是保证堆，也就是其两个子节点必须两个子堆的根
// down时，保证其两个子树为堆。

using namespace std;

const int N = 100010;

int n, m;
int h[N], cnt;

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    cnt = n;

    for (i = n / 2; i; i--)
        down(i);

    while (m--)
    {
        printf("%d ", h[1]);
        h[1] = h[cnt--];
        down(1);
    }

    puts("");

    return 0;
}