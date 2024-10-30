/*****************************************************************
 * 题目：「RiOI-2」hacker
 * 描述：讲一个数通过与或操作变成另一个数需要的次数。
 * 思路：按位比较。
 * 对象：BitCost模拟位运算代价。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class BitCost
{
private:
public:
    int get_cost(ll A, ll B)
    {
        if (A == B)
        {
            return 0;
        }

        bool diff1 = false;
        bool diff2 = false;
        while (A != 0 || B != 0)
        {
            // cout << A << " " << B << endl;
            if ((A & 1) == 1 && (B & 1) == 0)
            {
                diff1 = true;
            }

            if ((A & 1) == 0 && (B & 1) == 1)
            {
                diff2 = true;
            }
            A >>= 1;
            B >>= 1;

            if (diff1 && diff2)
            {
                return 2;
            }
        }

        return 1;
    }
};

int main()
{
    BitCost bc;

    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        ll a, b;
        cin >> a >> b;
        cout << bc.get_cost(a, b) << endl;
    }
    return 0;
}