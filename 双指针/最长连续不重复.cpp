#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], s[N];

int main()
{
    scanf("%d", &n);
    int i, res = 0, j;
    for (i = 0; i < n; i++)
        scanf("%d", &q[i]);

    for (i = 0, j = 0; i < n; i++)
    {
        s[q[i]]++;
        while (j < i && s[q[i]] > 1)
            s[q[j++]]--;
        res = max(res, i - j + 1);
    }

    printf("%d\n", res);

    return 0;
}