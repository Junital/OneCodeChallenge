/**********************************************************
 * 题目：乘积最大3
 * 描述：N个和为M的数字，乘积最大值为多少？
 * 思路：先测试结论，然后将结论代入代码中。
        果然，结果最大的就是数字之间最接近的。
 * 对象：MaxMultiple模拟最大乘积。
 * 注意：注意时间和溢出问题。
        注意字典序。
 *********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

void test()
{
    int Sum = 100;
    int ans = 0;

    rep(x1, 1, Sum)
    {
        rep(x2, 1, Sum - x1)
        {
            rep(x3, 1, Sum - x2 - x1)
            {
                rep(x4, 1, Sum - x3 - x2 - x1)
                {
                    int x5 = Sum - x4 - x3 - x2 - x1;

                    if (x1 * x2 * x3 * x4 * x5 > ans)
                    {
                        ans = x1 * x2 * x3 * x4 * x5;
                        cout << x1 << " " << x2 << " " << x3
                             << " " << x4 << " " << x5 << endl;
                    }
                }
            }
        }
    }
}

class MaxMultiple
{
private:
public:
    /* 计算，输入数字的数量和总和。 */
    vector<int> cal(int Num, int Sum)
    {
        vector<int> Ans;                // 答案
        int Base = Sum / Num;           // 计算输出数字中最小的数。
        int CeilNum = Sum - Base * Num; // 稍大数字的个数

        rep(i, 1, Num - CeilNum)
        {
            Ans.push_back(Base);
        }

        rep(i, 1, CeilNum)
        {
            Ans.push_back(Base + 1);
        }

        return Ans;
    }
};

int main()
{
    // test();
    int num, sum;
    MaxMultiple mm;

    cin >> sum >> num;
    vector<int> ans = mm.cal(num, sum);

    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}