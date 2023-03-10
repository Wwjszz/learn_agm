#include <iostream>
#include <algorithm>

using namespace std;
const int N = 100010;
int n, s, t;
pair<int, int> r[N];

int main()
{
    scanf("%d%d", &s, &t);
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++)
        scanf("%d%d", &r[i].first, &r[i].second);

    sort(r, r + n);

    int j, res = 0;
    bool f = 0;
    for (i = 0; i < n; i++)
    {
        j = i;
        int mr = -2e9;
        while (j < n && r[j].first <= s)
        {
            mr = max(mr, r[j].second);
            j++;
        }

        if (mr < s)
            break;

        res++;
        if (mr >= t)
        {
            f = 1;
            break;
        }

        s = mr;
        i = j - 1;
    }

    if (!f)
        res = -1;
    printf("%d\n", res);

    return 0;
}