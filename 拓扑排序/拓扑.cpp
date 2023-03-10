#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{

    int hh = 0, tt = -1, i;
    for (i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i;

    while (hh <= tt)
    {
        int b = q[hh++];

        for (i = h[b]; ~i; i = ne[i])
        {
            int c = e[i];
            if (!(--d[c]))
                q[++tt] = c;
        }
    }

    return tt == n - 1;
}

int main()
{

    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof(h));

    int i;
    for (i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        d[b]++;
        add(a, b);
    }

    if (!topsort())
        puts("-1");
    else
    {
        for (i = 0; i < n; i++)
            printf("%d ", q[i]);
        puts("");
    }

    return 0;
}