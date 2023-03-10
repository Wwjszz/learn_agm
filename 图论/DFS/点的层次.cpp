#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int N = 100010;
int n, m;
int e[N], ne[N], h[N], idx;
int d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
    memset(d, -1, sizeof(d));

    queue<int> q;
    q.push(1);
    d[1] = 0;

    while (q.size())
    {
        int b = q.front();
        q.pop();

        if (b == n)
            break;

        int i;
        for (i = h[b]; ~i; i = ne[i])
        {
            int x = e[i];
            if (d[x] != -1)
                continue;
            d[x] = d[b] + 1;
            q.push(x);
        }
    }
    return d[n];
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
        add(a, b);
    }

    printf("%d\n", bfs());

    return 0;
}