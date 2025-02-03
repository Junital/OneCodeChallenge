/*****************************************************************
 * 题目：[语言月赛202303] Out for Dinner B
 * 描述：根据点的菜品，计算是否打折。
 * 思路：构造黑名单和白名单，进行判断。
 * 对象：BlackAndWhiteList模拟黑白名单。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BlackAndWhiteList
{
private:
    set<T> WhiteList;
    set<T> BlackList;

public:
    /* 初始化，输入黑白名单。 */
    BlackAndWhiteList(set<T> white_list, set<T> black_list) : WhiteList(white_list), BlackList(black_list) {}

    /* 判断是否符合。 */
    bool judge(set<T> arr)
    {
        for (auto w : WhiteList)
        {
            if (arr.count(w) < 1)
            {
                return false;
            }
        }

        for (auto b : BlackList)
        {
            if (arr.count(b) > 0)
            {
                return false;
            }
        }

        return true;
    }
};

struct PackageDiscount
{
    BlackAndWhiteList<char> bawl;
    int discount;
};

int main()
{
    const vector<PackageDiscount> Discounts = {{BlackAndWhiteList<char>({'B'}, {'C'}), 8}, {BlackAndWhiteList<char>({'C'}, {'B'}), 7}, {BlackAndWhiteList<char>({'C', 'B'}, {}), 6}};

    long long cost;
    string dishes;

    cin >> cost;
    cin >> dishes;
    set<char> query(dishes.begin(), dishes.end());

    bool payed = false;
    for (auto pd : Discounts)
    {
        if (pd.bawl.judge(query))
        {
            cout << cost / 10 * pd.discount << endl;
            payed = true;
            break;
        }
    }

    if (!payed)
    {
        cout << cost << endl;
    }
    return 0;
}
