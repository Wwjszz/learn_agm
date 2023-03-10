/*
 * 朴素Dijkstra
 * 时间复杂度为O(n^2)
 * 所以适合 稠密图 (边多点少)
 * */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
int n, m;
int g[N][N], d[N];
bool f[N];

int dijkstra(int s, int t)
{
    memset(d, 0x3f, sizeof(d));

    d[s] = 0;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int t = -1;
        for (j = 1; j <= n; j++)
            if (!f[j] && (t == -1 || d[t] > d[j]))
                t = j;

        for (j = 1; j <= n; j++)
            d[j] = min(d[j], d[t] + g[t][j]);

        f[t] = 1;
    }

    if (d[t] == 0x3f3f3f3f)
        return -1;
    else
        return d[t];
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof(g));
    int i;
    for (i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }

    printf("%d\n", dijkstra(1, n));

    return 0;
}