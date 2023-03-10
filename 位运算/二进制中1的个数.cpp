#include <iostream>

using namespace std;

int main()
{
    int n, x, s, i;
    scanf("%d", &n);
    while (n--)
    {
        s = 0;
        scanf("%d", &x);

        for (i = x; i; i -= i & -i)
            s++;

        printf("%d ", s);
    }

    return 0;
}