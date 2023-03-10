#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

// 每一步都是先满足子堆一直往外拓展到整个堆。

const int N = 100010;

/*
 * h[k]: 堆中下标为k的节点值
 * hp[k]: 第k个插入的数的下标
 * ph[k]: 下标为k的节点的插入次序
 * */
int h[N], ph[N], hp[N], cnt;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(t, u);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        heap_swap(u, u / 2);
        u = u / 2;
    }
}

int main()
{
    int n, m = 0;
    scanf("%d", &n);
    while (n--)
    {
        char op[5];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            cnt++;
            m++;
            hp[cnt] = m, ph[m] = cnt;
            h[cnt] = x;
            up(cnt);
        }
        else if (!strcmp(op, "PM"))
            printf("%d\n", h[1]);
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, cnt);
            cnt--;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, cnt);
            cnt--;
            // up和down两个操作最多执行一个
            up(k);
            down(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            // up和down两个操作最多执行一个
            up(k);
            down(k);
        }
    }

    return 0;
}