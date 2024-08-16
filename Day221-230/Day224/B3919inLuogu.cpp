/*****************************************************************
 * 题目：[语言月赛 202401] 二进制与一
 * 描述：问一个数需要加多少才能使某个位为1。
 * 思路：移位操作。
 * 函数：get_bit_digit用于获得某个比特位的数。
 * 注意：注意数据的范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll unsigned int                           // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Shift
{
private:
    ll Idx; // 移位编码

public:
    /* 初始化，输入移位编码 */
    Shift(ll idx) : Idx(idx) {}

    /* 获得第idx位的二进制编码。 */
    ll get_bit_digit(ll Num)
    {
        return (Num >> (Idx - 1)) & 1;
    }

    /* 获得截断某位之后所有的编码。 */
    ll truncate(ll Num)
    {
        return (Num >> (Idx - 1)) << (Idx - 1);
    }
};

int main()
{
    ll Number, query_num;
    cin >> Number >> query_num;

    ll Sum = 0;
    rep(i, 1, query_num)
    {
        ll query;
        cin >> query;
        Shift s(query);
        if (s.get_bit_digit(Number) != 1)
        {
            ll new_number = s.truncate(Number) + (1 << (query - 1));
            Sum += new_number - Number;
            Number = new_number;
        }
    }

    cout << Sum << endl;
    return 0;
}