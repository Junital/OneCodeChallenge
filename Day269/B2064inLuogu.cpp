/*****************************************************************
 * 题目：斐波那契数列
 * 描述：求斐波那契数列中索引对应的值。
 * 思路：先初始化，之后进行请求。
 * 对象：Fibonacci模拟斐波那契数列。
 * 注意：注意输出样式。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class Fibonacci
{
private:
    vector<ll> Arr;

public:
    /* 初始化，输入大小。 */
    Fibonacci(int Size)
    {
        Arr.resize(Size);

        Arr[0] = 1;
        Arr[1] = 1;

        rep(i, 2, Size - 1)
        {
            Arr[i] = Arr[i - 1] + Arr[i - 2];
        }
    }

    /* 重载定位。 */
    const ll &operator[](int index) const
    {
        assert(index <= Arr.size());
        return Arr[index - 1];
    }
};

int main()
{
    Fibonacci f(30);
    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        int idx;
        cin >> idx;
        cout << f[idx] << endl;
    }
    return 0;
}
