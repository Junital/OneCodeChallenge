/**********************************************************
 * 题目：[AHOI2021初中组] 超市购物
 * 描述：超市会打折，将零头抹去。
 * 思路：double和int互相转换。
 * 函数：SuperMarket模拟超市。
 * 注意：留好接口，具备拓展性。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 超市 */
class SuperMarket
{
private:
    double DiscountRate;

    /* 抹去零头。 */
    double move_cents(double Money)
    {
        return (double)(int)(Money * 10) / 10;
    }

public:
    /* 初始化，输入打折率。 */
    SuperMarket(double discount) : DiscountRate(discount)
    {
        assert(discount > 0 && discount <= 1);
    }

    /* 输入商品的价格和对应的购买量，输出价格。 */
    double buy(vector<pair<double, int>> Goods, bool discount = false)
    {
        double Sum = 0; // 总价
        for (auto goods : Goods)
        {
            double price = goods.first;
            double num = goods.second;
            Sum += num * price;
        }

        if (discount)
        {
            Sum = Sum * DiscountRate;
        }

        return move_cents(Sum); // 抹去零头
    }
};

int main()
{
    const double rate = 0.85; // 八五折

    int GoodsNum;
    vector<pair<double, int>> Goods;
    SuperMarket sm(rate);

    cin >> GoodsNum;
    rep(i, 1, GoodsNum)
    {
        double price;
        int num;
        cin >> price >> num;
        Goods.push_back(make_pair(price, num));
    }

    cout << fixed << setprecision(1) << sm.buy(Goods, true) << endl;
    return 0;
}
