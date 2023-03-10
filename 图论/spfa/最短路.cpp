#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010;
int n, m;
int e[N], ne[N], h[N], idx, w[N];
bool f[N];
int d[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa()
{
    memset(d, 0x3f, sizeof d);
    memset(f, 0, sizeof f);

    d[1] = 0;
    queue<int> q;
    q.push(1);
    f[1] = 1;
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
                if (!f[c])
                {
                    f[c] = 1;
                    q.push(c);
                }
            }
        }
    }
    return d[n];
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

    int t = spfa();

    if (t == 0x3f3f3f3f)
        puts("impossible");
    else
        printf("%d\n", t);

    return 0;
}