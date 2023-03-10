#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010;
int n, m;
int e[N], ne[N], h[N], idx, w[N];
bool f[N];
int d[N], cnt[N]; // cnt : 该点最短路的边数 边数大于等于n则存在负环
// int cnt1[N] 或者看某个节点入队n次，则存在负环
/*
 * 用一个n大小的数组来代表每个点的松弛次数。因为SPFA算法里的松弛，和Bellman-ford算法里的松弛一样。
 * Bellman-ford算法里，对同一个点的松弛次数，在极端情况下，可以想象把这些松弛次数分配到每一次迭代求解中去，
 * 而迭代求解一共只有n-1次。所以一旦某个点的松弛次数等于了n，那么就说明有负环。
 * */

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa()
{
    memset(d, 0x3f, sizeof d);

    queue<int> q;

    int i;
    for (i = 1; i <= n; i++)
        q.push(i), f[i] = 1;

    while (q.size())
    {
        int b = q.front();
        q.pop();

        f[b] = 0;
        int i;
        for (i = h[b]; ~i; i = ne[i])
        {
            int c = e[i];
            if (d[c] > d[b] + w[i])
            {
                d[c] = d[b] + w[i];
                cnt[c] = cnt[b] + 1;

                if (cnt[c] >= n)
                    return true;

                if (!f[c])
                {
                    /*
                     * cnt1[N] += 1
                     * cnt1[N] >= n 入队表示对一个点松弛
                     * */
                    f[c] = 1;
                    q.push(c);
                }
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    int i;
    for (i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    if (spfa())
        puts("Yes");
    else
        puts("No");
    return 0;
}