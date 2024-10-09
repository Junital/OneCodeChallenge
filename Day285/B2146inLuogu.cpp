/*********************************************
 * 题目：Hermite 多项式
 * 描述：分段、递归函数。
 * 思路：模拟。
 * 对象：Hermite模拟多项式。
 * 注意：封装完善。
 ********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Hermite
{
private:
    /* 内部调用函数 */
    int hermite(int n, int x)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return 2 * x;
        }
        else if (n > 1)
        {
            return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
        }
        return -1;
    }

public:
    int query(int n, int x)
    {
        return hermite(n, x);
    }
};

int main()
{
    Hermite h;
    int n, x;
    cin >> n >> x;

    cout << h.query(n, x) << endl;
    return 0;
}