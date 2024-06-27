/**********************************************************
 * 题目：求分数序列和
 * 描述：分子为q、分母为p；q_i+1 =q_i + p_i；p_i+1 = q_1
        p_1 = 1, q_1 = 2
 * 思路：遍历求和。
 * 对象：FibonacciFraction模拟斐波那契分数。
 * 注意：注意数据范围与精度。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class FibonacciFraction
{
private:
    const int Init_Deno = 1;  // 初始分母
    const int Init_Numer = 2; // 初始分子

public:
    /* 输入项数，输出求和答案。 */
    double sum(int Num)
    {
        double Sum = 0;
        int Deno = Init_Deno;
        int Numer = Init_Numer;

        rep(i, 1, Num)
        {
            Sum += Numer * 1.0 / Deno;
            swap(Deno, Numer);
            Numer += Deno;
        }

        return Sum;
    }
};

int main()
{
    FibonacciFraction ff;

    int n;
    cin >> n;
    cout << fixed << setprecision(4) << ff.sum(n) << endl;
    return 0;
}
