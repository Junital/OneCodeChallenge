/*****************************************************************
 * 题目：求出 e 的值
 * 描述：根据精度给出e的值。
 * 思路：公式计算。
 * 对象：e模拟e。
 * 注意：注意数据精度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class e
{
private:
public:
    /* 根据给定的精度值，求出e的值。 */
    double get(int Precision)
    {
        long double ans = 1;
        double Multiple = 1; // 这里double精度才准确
        rep(i, 1, Precision)
        {
            Multiple *= i;
            ans += 1.0 / Multiple;
        }

        return ans;
    }
};

int main()
{
    e e1;

    int pre;
    cin >> pre;
    cout << fixed << setprecision(10) << e1.get(pre) << endl;
    return 0;
}