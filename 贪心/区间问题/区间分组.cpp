#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int N = 100010;
int n, num;
pair<int, int> r[N];

int main()
{
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++)
        scanf("%d%d", &r[i].first, &r[i].second);

    sort(r, r + n);

    priority_queue<int, vector<int>, greater<int>> heap;
    for (i = 0; i < n; i++)
    {
        if (heap.empty() || heap.top() >= r[i].first)
            ;
        else
            heap.pop();

        heap.push(r[i].second);
    }

    printf("%d\n", heap.size());

    return 0;
}