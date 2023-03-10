#include <iostream>
#include <algorithm>

using namespace std;
const int N = 50010;
int n;
pair<int, int> a[N];

int main()
{

    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++)
    {
        int w, s;
        scanf("%d%d", &w, &s);
        a[i] = {w + s, s};
    }

    sort(a, a + n);

    int res = -2e9, sum = 0;
    for (i = 0; i < n; i++)
    {
        int s = a[i].second, w = a[i].first - s;
        res = max(res, sum - s);
        sum += w;
    }

    printf("%d\n", res);
    return 0;
}