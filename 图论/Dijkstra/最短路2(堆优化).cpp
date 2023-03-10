/*
 * 堆优化Dijkstra
 * 时间复杂度为O(n) / O(mlogn)
 * 所以适合 稠密图 (边多点少)
 * */
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

const int N = 1e6 + 10;
int n, m;
int e[N], ne[N], h[N], idx, w[N];
int d[N];
bool f[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    memset(d, 0x3f, sizeof(d));

    d[1] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, 1});
    while (q.size())
    {
        auto b = q.top();
        q.pop();

        int dis = b.first, t = b.second;

        if (f[t])
            continue;
        f[t] = true;

        int i;
        for (i = h[t]; ~i; i = ne[i])
        {
            int c = e[i];
            if (d[c] > dis + w[i])
            {
                d[c] = dis + w[i];
                q.push({d[c], c});
            }
        }
    }

    if (d[n] == 0x3f3f3f3f)
        return -1;
    return d[n];
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof(h));

    int i;
    for (i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    printf("%d\n", dijkstra());

    return 0;
}