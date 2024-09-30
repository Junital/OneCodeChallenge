/*****************************************************************
 * 题目：计算书费
 * 描述：购买书籍，看看花了多少钱。
 * 思路：用数组初始化进行模拟。
 * 对象：Shop模拟商店。
 * 注意：注意拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Shop
{
private:
    vector<pair<string, double>> Goods;

public:
    /* 初始化，输入商品价格数组。 */
    Shop(vector<pair<string, double>> goods) : Goods(goods) {}

    /* 购买输入序列号. */
    double buy(vector<int> Sheet)
    {
        assert(Sheet.size() == Goods.size());

        int sheet_size = Sheet.size();
        double sum = 0;
        rep(i, 0, sheet_size - 1)
        {
            sum += Sheet[i] * Goods[i].second;
        }
        return sum;
    }
};

int main()
{
    const vector<pair<string, double>> goods = {
        make_pair("计算概论", 28.9),
        make_pair("数据结构与算法", 32.7),
        make_pair("数字逻辑", 45.6),
        make_pair("C++程序设计教程", 78),
        make_pair("人工智能", 35),
        make_pair("计算机体系结构", 86.2),
        make_pair("编译原理", 27.8),
        make_pair("操作系统", 43),
        make_pair("计算机网络", 56),
        make_pair("JAVA程序设计", 65)};

    Shop s(goods);
    string arr_str;
    getline(cin, arr_str);

    vector<int> Sheet;

    istringstream stream(arr_str);

    int num;
    while (stream >> num)
    {
        // cout << num << endl;
        Sheet.push_back(num);
    }

    cout << fixed << setprecision(1) << s.buy(Sheet) << endl;
    return 0;
}