#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Floyd 算法 d[k][i][j]表示从i点只经过1-k这些中间点到j点的最短距离
 * 递推式 : d[k][i][j] = min(d[k-1][i][j],d[k-1][i][k] + d[k-1][k][j])
 * */

const int N = 210, INF = 1e9;
int n, m, k;
int d[N][N];

void floyd()
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;

    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
    }

    floyd();

    while (k--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (d[a][b] > INF / 2)
            puts("impossible");
        else
            printf("%d\n", d[a][b]);
    }

    return 0;
}