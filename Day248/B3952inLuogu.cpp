/*****************************************************************
 * 题目：[GESP202403 一级] 小杨买书
 * 描述：输入金额，输出能买多少本、剩多少零钱。
 * 思路：除法与取模。
 * 函数：Buy模拟购买操作。
 * 注意：注意代码可拓展性，
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

pair<int, int> Buy(int Money, int Price)
{
    int Num = Money / Price;
    int Exchange = Money % Price;

    return make_pair(Num, Exchange);
}

int main()
{
    const int price = 13;
    int money;

    cin >> money;

    auto res = Buy(money, price);
    cout << res.first << endl;
    cout << res.second << endl;
    return 0;
}
