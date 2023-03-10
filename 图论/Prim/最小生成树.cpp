#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], d[N];
bool f[N];

int prim()
{
    memset(d, 0x3f, sizeof d);
    memset(f, 0, sizeof f);

    int res = 0;

    int i, j;
    for (i = 0; i < n; i++)
    {
        int t = -1;
        for (j = 1; j <= n; j++)
            if (!f[j] && (t == -1 || d[t] > d[j]))
                t = j;

        if (i && d[t] == INF)
            return INF;

        if (i)
            res += d[t];
        f[t] = 1;

        for (j = 1; j <= n; j++)
            d[j] = min(d[j], g[t][j]);
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF)
        puts("impossible");
    else
        printf("%d\n", t);

    return 0;
}