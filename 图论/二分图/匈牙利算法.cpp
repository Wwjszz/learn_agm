#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool f[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int u)
{
    int i;
    for (i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!f[j])
        {
            f[j] = true;
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = u;
                return 1;
            }
        }
    }
    return false;
}

/**/

int main()
{
    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int res = 0, i;
    for (i = 1; i <= n1; i++)
    {
        memset(f, 0, sizeof f);
        if (find(i))
            res++;
    }

    printf("%d\n", res);

    return 0;
}