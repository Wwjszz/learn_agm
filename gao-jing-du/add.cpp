#include <iostream>
#include <vector>

using namespace std;

// 不压位 也就是一个元素存储一个位(0-9) 倒着输入
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return add(B, A);

    vector<int> C;
    int t = 0, i, size = A.size();
    for (i = 0; i < size; i++)
    {
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t)
        C.push_back(t);
    return C;
}

const int base = 1000000000;

// 压9位 也就是一个元素存储一个9位数 A B也是如此
vector<int> add9(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return add9(B, A);

    vector<int> C;
    int t = 0, i, size = A.size();
    for (i = 0; i < size; i++)
    {
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % base);
        t /= base;
    }
    if (t)
        C.push_back(t);
    return C;
}

// 压9位输入
int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;

    for (int i = a.size() - 1, s = 0, j = 0, t = 1; i >= 0; i--)
    {
        s += (a[i] - '0') * t;
        j++, t *= 10;
        if (j == 9 || i == 0)
        {
            A.push_back(s);
            s = j = 0;
            t = 1;
        }
    }

    for (int i = b.size() - 1, s = 0, j = 0, t = 1; i >= 0; i--)
    {
        s += (b[i] - '0') * t;
        j++, t *= 10;
        if (j == 9 || i == 0)
        {
            B.push_back(s);
            s = j = 0;
            t = 1;
        }
    }

    auto C = add9(A, B);

    printf("%d", C.back()); // 去除前导0
    for (int i = C.size() - 2; i >= 0; i--)
        printf("%09d", C[i]);
    puts("");

    return 0;
}