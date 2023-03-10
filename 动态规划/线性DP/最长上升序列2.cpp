#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int n;
int a[N], p[N];

int main()
{

    scanf("%d", &n);

    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int len = 0;
    for (i = 1; i <= n; i++)
    {
        int l = 0, r = len;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (p[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, r + 1);
        p[r + 1] = a[i];
    }

    printf("%d\n", len);
    return 0;
}