/*****************************************************************
 * 题目：[JRKSJ R6] Nothing
 * 描述：计算区间内的奇数数目。
 * 思路：只要知道最小的奇数和最大奇数就能知道数量。
 * 对象：OddNum模拟计算区间奇数数量。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class OddNum
{
private:
public:
    /* 输入区间收尾，输出奇数数量。 */
    ll query(ll Begin, ll End)
    {
        // cout << Begin << End << endl;
        ll begin, end;

        if (Begin % 2 == 0)
        {
            begin = Begin + 1;
        }
        else
        {
            begin = Begin;
        }

        if (End % 2 == 0)
        {
            end = End - 1;
        }
        else
        {
            end = End;
        }

        return (end - begin) / 2 + 1;
    }
};

int main()
{
    int query_num;
    cin >> query_num;
    OddNum on;

    rep(i, 1, query_num)
    {
        ll begin, end;
        cin >> begin >> end;
        cout << on.query(begin, end) << endl;
    }
    return 0;
}