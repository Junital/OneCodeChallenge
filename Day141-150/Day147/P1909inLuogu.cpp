/******************************************************
 * 题目：[NOIP2016 普及组] 买铅笔
 * 描述：只能买整盒的铅笔，要买够x支用哪种方案最便宜？
 * 思路：逐一比较，选出最小的钱。
 * 对象：BoxPencil模拟盒装铅笔。
 * 注意：封装具备拓展性。
 ******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class BoxPencil
{
private:
    int ProductNum;
    vector<pair<int, int>> Products;
    const int MAXPRICE = 1 << 30;

    /* 计算买某个产品需要多少钱。 */
    int buy(int Command, pair<int, int> Product)
    {
        int Capacity = Product.first;
        int Price = Product.second;

        int Num = (Command % Capacity == 0)
                      ? Command / Capacity
                      : Command / Capacity + 1;

        return Num * Price;
    }

public:
    /* 初始化，输入铅笔盒方案的个数。 */
    BoxPencil(int num) : ProductNum(num)
    {
        rep(i, 1, ProductNum)
        {
            int capacity, price;
            cin >> capacity >> price;

            Products.push_back(make_pair(capacity, price));
        }
    }

    /* 比较方案，输出最小的价钱。 */
    int compare(int Command)
    {
        int MinPrice = MAXPRICE;
        for (auto Product : Products)
        {
            MinPrice = min(MinPrice, buy(Command, Product));
        }

        return MinPrice;
    }
};

int main()
{
    const int ProductNum = 3;

    int Command;
    cin >> Command;

    BoxPencil bp(ProductNum);

    cout << bp.compare(Command) << endl;
    return 0;
}
