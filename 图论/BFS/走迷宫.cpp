#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int N = 110;
int n, m;
int ma[N][N], d[N][N];

int bfs()
{
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

    queue<pair<int, int>> q;

    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    q.push({0, 0});

    while (q.size())
    {
        auto b = q.front();
        q.pop();

        if (b.second == m - 1 && b.first == n - 1)
            break;

        int i;
        for (i = 0; i < 4; i++)
        {
            int x = b.first + dx[i], y = b.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && !ma[x][y] && d[x][y] == -1)
            {
                d[x][y] = d[b.first][b.second] + 1;
                q.push({x, y});
            }
        }
    }
    return d[n - 1][m - 1];
}

int main()
{
    scanf("%d%d", &n, &m);

    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &ma[i][j]);

    printf("%d\n", bfs());

    return 0;
}