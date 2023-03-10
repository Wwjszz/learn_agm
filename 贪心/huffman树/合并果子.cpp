#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1010;
int n;
priority_queue<int, vector<int>, greater<int>> que;

int main()
{

    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        que.push(a);
    }

    int res = 0;
    while (que.size() > 1)
    {
        int a = que.top();
        que.pop();
        int b = que.top();
        que.pop();
        res += a + b;
        que.push(a + b);
    }

    printf("%d\n", res);

    return 0;
}