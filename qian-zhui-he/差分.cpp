/**
 * 差分
 * a[i] = s[1] + ... + s[i]
 * 要求a数组，只需遍历s[i]累加即可
 * 对s[i]进行修改，显然不会影响i之前的a数组的值，但会影响后面，举例：若s[i]+=c,a[1]~a[i-1]都不会有
 * 变化，但是a[i]~a[n],n为最后一个的下标，所以如果让a[l]~a[r]加减某个c，则只需要让s[l]+=c,s[r+1]-=c
 * 就可以让求得的a[l]~a[r]加减某个c并且不会对其他数产生影响
 */
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], s[N];

void insert(int l, int r, int c)
{
    s[l] += c;
    s[r + 1] -= c;
}

int main()
{
    scanf("%d%d", &n, &m);
    int i;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        insert(i, i, a[i]);
    }

    int l, r, c;
    while (m--)
    {
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for (i = 1; i <= n; i++)
    {
        s[i] += s[i - 1];
        printf("%d ", s[i]);
    }

    return 0;
}