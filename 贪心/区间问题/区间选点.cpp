#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int n;
pair<int, int> r[N];

int main()
{
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++)
        scanf("%d%d", &r[i].second, &r[i].first);

    sort(r, r + n);

    int res = 0, lr = -2e9;
    for (i = 0; i < n; i++)
        if (r[i].second > lr)
        {
            res++;
            lr = r[i].first;
        }

    printf("%d\n", res);

    return 0;
}