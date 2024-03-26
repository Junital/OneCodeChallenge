/***********************************************
 * 题目：HXY玩卡片
 * 描述：组合数字，使其被90整除
 * 思路：先统计一下只有0、5还满足条件的数字。
        统计了一下，好像只有9个5才有戏。

 * 对象：FiveZero模拟只有0和5的数字。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

#define ll long long // 定义长整型

class FiveZero
{
private:
    /* 判断一个数字是否符合只有数字0和5。 */
    bool judge(ll Num)
    {
        while (Num != 0)
        {
            int digit = Num % 10;
            Num /= 10;

            if (digit != 0 && digit != 5)
            {
                return false;
            }
        }

        return true;
    }

public:
    /* 测试函数，输出符合90倍数的整数。 */
    void test()
    {
        for (ll i = 55555555550; i <= 1e15; i += 90)
        {
            if (judge(i))
            {
                cout << i << endl;
            }
        }
    }

    /* 卡片组合，输入卡片的数量。 */
    string arrange(int CardNum)
    {
        map<int, int> fivezero;
        rep(i, 1, CardNum)
        {
            int x;
            cin >> x;

            fivezero[x]++;
        }

        if (fivezero[5] > 9 && fivezero[0] != 0)
        {
            string ans = "555555555";

            rep(i, 1, fivezero[0])
            {
                ans += '0';
            }
            return ans;
        }
        else if (fivezero[0] != 0)
        {
            return "0";
        }
        else
        {
            return "-1";
        }
    }
};

int main()
{
    FiveZero fz;

    int CardNum;
    cin >> CardNum;

    cout << fz.arrange(CardNum) << endl;

    return 0;
}