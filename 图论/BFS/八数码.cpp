#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <unordered_map>

using namespace std;

string a;

int bfs()
{
    queue<string> q;
    unordered_map<string, int> d;

    q.push(a);
    d[a] = 0;

    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

    string end = "12345678x";
    while (q.size())
    {
        auto b = q.front();
        q.pop();

        if (b == end)
            return d[b];

        int dis = d[b];
        int k = b.find('x');
        int x = k / 3, y = k % 3;
        int i;
        for (i = 0; i < 4; i++)
        {
            int x1 = x + dx[i], y1 = y + dy[i];
            if (x1 >= 0 && x1 < 3 && y1 >= 0 && y1 < 3)
            {
                swap(b[x1 * 3 + y1], b[k]);
                if (!d.count(b))
                {
                    q.push(b);
                    d[b] = dis + 1;
                }
                swap(b[x1 * 3 + y1], b[k]);
            }
        }
    }
    return -1;
}

int main()
{
    char s;

    int i;
    for (i = 0; i < 9; i++)
    {
        cin >> s;
        a += s;
    }

    cout << bfs() << endl;

    return 0;
}