/*****************************************************************
 * 题目：[语言月赛 202406] 天然气计价
 * 描述：对每个月的天然气进行计价。
 * 思路：求和计算。
 * 对象：NaturalGasPricing模拟天然气计价。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class NaturalGasPricing
{
private:
    const vector<int> Thresholds = {310, 520};
    const vector<double> Prices = {3.0, 3.3, 4.2};

public:
    const int MONTHNUM = 12;

    /* 计价。 */
    vector<double> pricing(vector<int> gas)
    {
        int size = gas.size();
        assert(size == MONTHNUM);

        vector<double> price;
        int sum = 0;
        for (auto g : gas)
        {
            sum += g;
            if (sum <= Thresholds[0])
            {
                price.push_back(g * Prices[0]);
            }
            else if (sum <= Thresholds[1])
            {
                int overflow = min(sum - Thresholds[0], g);
                price.push_back(overflow * Prices[1] +
                                (g - overflow) * Prices[0]);
            }
            else
            {
                int overflow1 = min(sum - Thresholds[1], g);
                int overflow2 = min(max(Thresholds[1] - (sum - g), 0),
                                    Thresholds[1] - Thresholds[0]);

                price.push_back(overflow1 * Prices[2] +
                                overflow2 * Prices[1] +
                                (g - overflow1 - overflow2) * Prices[0]);
            }
        }

        return price;
    }
};

int main()
{
    NaturalGasPricing ngp;
    vector<int> gases(ngp.MONTHNUM);

    rep(i, 0, ngp.MONTHNUM - 1)
    {
        cin >> gases[i];
    }

    auto res = ngp.pricing(gases);
    for (auto e : res)
    {
        cout << fixed << setprecision(1) << e << endl;
    }
    return 0;
}