#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;
int n, m;
int e[M], ne[M], h[N], idx;
int col[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c)
{
    col[u] = c;

    int i;
    for (i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!col[j])
        {
            if (!dfs(j, 3 - c))
                return false;
        }
        else if (col[j] == c)
            return false;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    int i;
    for (i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    bool f = 1;
    for (i = 1; i <= n && f; i++)
        if (!col[i])
            f = dfs(i, 1);

    puts(f ? "Yes" : "No");

    return 0;
}