#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << N;
int n, m;
LL dp[N][M];
vector<int> states[M];
bool st[M];

int main()
{
    while (cin >> n >> m, n || m)
    {

        int i, j;
        for (i = 0; i < 1 << n; i++)
        {
            int cnt = 0;
            bool is = true;
            for (j = 0; j < n; j++)
            {
                if (i >> j & 1)
                {
                    if (cnt & 1)
                    {
                        is = false;
                        break;
                    }
                    cnt = 0;
                }
                else
                    cnt++;
            }
            if (cnt & 1)
                is = false;
            st[i] = is;
        }

        for (i = 0; i < 1 << n; i++)
        {
            states[i].clear();
            for (j = 0; j < 1 << n; j++)
                if ((i & j) == 0 && st[i | j])
                    states[i].push_back(j);
        }

        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (i = 1; i <= m; i++)
            for (j = 0; j < 1 << n; j++)
                for (auto k : states[j])
                    dp[i][j] += dp[i - 1][k];

        cout << dp[m][0] << endl;
    }

    return 0;
}