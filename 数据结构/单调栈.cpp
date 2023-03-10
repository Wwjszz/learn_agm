// acwing 830.单调栈
#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt;

int main()
{
    int n, x;
    cin >> n;
    while (n--)
    {
        scanf("%d", &x);
        while (tt && stk[tt] >= x)
            tt--;
        if (!tt)
            printf("-1 ");
        else
            printf("%d ", stk[tt]);
        stk[++tt] = x;
    }
    return 0;
}