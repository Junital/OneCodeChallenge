/***************************************************************
 * 题目：第一次，第二次，成交！
 * 描述：求出活力最多的价格，能让出价大于等于此价格的商家购买，让自己获利最多。
 * 思路：遍历一下。
 * 对象：DecidePrice模拟价格的确定。
 * 注意：应该不会溢出，逻辑注意。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class DecidePrice
{
private:
    int Goods;          // 货物数量
    int Buyers;         // 商家数量
    vector<int> Prices; // 商家商定的价格
    int MinPrice;       // 最低价格
    int Profit;         // 能赚到的钱

    /* 根据某个价格计算会买的商家个数。 */
    int getbuyers(int price)
    {
        int RejectNum = lower_bound(Prices.begin(), Prices.end(), price) - Prices.begin();

        return Buyers - RejectNum;
    }

    /* 计算某个价格可以获的利。 */
    int makemoney(int price)
    {
        int buyernum = getbuyers(price);

        return min(buyernum, Goods) * price;
    }

    /* 计算，获得最低价格和赚到的钱。 */
    void calculate()
    {
        MinPrice = 1 << 30;
        Profit = 0;
        for (auto price : Prices)
        {
            int money = makemoney(price);
            if (money > Profit)
            {
                Profit = money;
                MinPrice = price;
            }
        }
    }

public:
    /* 初始化，输入货物数量和商家数量。 */
    DecidePrice(int goods, int buyers) : Goods(goods), Buyers(buyers)
    {
        /* 输入商家商定的价格。 */
        Prices.resize(Buyers);
        rep(i, 0, Buyers - 1)
        {
            cin >> Prices[i];
        }

        /* 进行计算，获得最低价格和对应赚到的钱。 */
        sort(Prices.begin(), Prices.end());
        calculate();
    }

    /* 获得最小价格。 */
    int getMinPrice()
    {
        return MinPrice;
    }

    /* 获得最大盈利 */
    int getProfit()
    {
        return Profit;
    }
};

int main()
{
    int goods, buyers;
    cin >> goods >> buyers;

    DecidePrice dp(goods, buyers);

    cout << dp.getMinPrice() << " " << dp.getProfit() << endl;

    return 0;
}