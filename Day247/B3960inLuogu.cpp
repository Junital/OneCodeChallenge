/*****************************************************************
 * 题目：[语言月赛 202404] 疯狂大减价
 * 描述：优惠券思路，满一定金额有优惠。
 * 思路：按照金额从大到小进行判断。
 * 对象：SalesOff模拟减价。
 * 注意：注意代码可拓展性，
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class SalesOff
{
private:
    vector<pair<int, int>> Sales; // 优惠券

public:
    /* 初始化，输入优惠需要满足的金额和优惠力度。 */
    SalesOff(vector<pair<int, int>> s) : Sales(s)
    {
        // 使用 lambda 表达式进行排序
        std::sort(Sales.begin(), Sales.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
                  { return a.first > b.first; });
    }

    /* 模拟优惠。 */
    int pay(int Total)
    {
        for (auto pii : Sales)
        {
            if (Total >= pii.first)
            {
                Total -= pii.second;
            }
        }

        return Total;
    }
};

int main()
{
    const vector<pair<int, int>> sales = {make_pair(100, 20), make_pair(200, 50)};
    SalesOff so(sales);

    int total;
    cin >> total;

    cout << so.pay(total) << endl;
    return 0;
}
