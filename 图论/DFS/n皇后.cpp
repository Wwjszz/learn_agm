#include <iostream>

using namespace std;

const int N = 10;

int n;
int queen[N];

void dfs(int u)
{
    if (u == n)
    {
        int i, j;
        for (i = 0; i < n; i++, puts(""))
            for (j = 0; j < n; j++)
            {
                if (j == queen[i])
                    printf("Q");
                else
                    printf(".");
            }
        puts("");
        return;
    }
    int i, j;
    for (i = 0; i < n; i++)
    {
        bool f = 1;
        for (j = 0; j < u && f; j++)
            if (queen[j] == i || u + i == j + queen[j] || u - i == j - queen[j])
                f = 0;
        if (!f)
            continue;
        queen[u] = i;
        dfs(u + 1);
        queen[u] = -1;
    }
}

int main()
{
    scanf("%d", &n);

    dfs(0);

    return 0;
}