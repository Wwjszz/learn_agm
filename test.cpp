#include <iostream>

using namespace std;

int jc(int n)
{
    return n ? n * jc(n - 1) : 1;
}

int main()
{
    char c;
    while (1)
    {
        scanf("%c", &c);
        printf("%c", c);
    }

    printf("%d\n", 20 * jc(20));
    return 0;
}