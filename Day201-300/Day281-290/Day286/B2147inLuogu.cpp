/*********************************************
 * 题目：求 f(x,n)
 * 描述：递归求解根号（嵌套根函数）。
 * 思路：模拟。
 * 对象：NestedRadicalFunc模拟嵌套根函数
 * 注意：保留两位小数。
 ********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class NestedRadicalFunc
{
private:
    /* 循环嵌套函数。 */
    double func(double x, int n)
    {
        double res = x;
        rep(i, 1, n)
        {
            res += i;
            res = sqrt(res);
        }

        return res;
    }

public:
    /* 请求，输入n和x。 */
    double query(double x, int n)
    {
        return func(x, n);
    }
};

int main()
{
    NestedRadicalFunc nrf;
    int n;
    double x;
    cin >> x >> n;

    cout << fixed << setprecision(2) << nrf.query(x, n) << endl;
    return 0;
}