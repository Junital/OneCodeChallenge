/*****************************************************************
 * 题目：[语言月赛 202404] 游乐场
 * 描述：模拟，每天给零花钱，但有上限，每次去游乐园都会尽可能做旋转木马。
        问最后能坐几次。
 * 思路：模拟。
 * 空间：Tools模拟工具包。
 * 注意：要考虑到所有情况，不能有遗漏。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
    /* 四舍五入 */
    int Approximate(double Num)
    {
        double Ceil = ceil(Num);
        double Floor = floor(Num);

        if (Ceil - Num <= Num - Floor)
        {
            return (int)Ceil;
        }
        else
        {
            return (int)Floor;
        }
    }
};

using namespace Tools;

int main()
{
    const int MAXMONEY = 50;
    const int CAROUSEL = 8;
    int size;
    cin >> size;

    vector<int> date(size + 1);
    date[0] = 0;

    int play_cnt = 0;
    int money = 0;
    rep(i, 1, size)
    {
        cin >> date[i];
        money += date[i] - date[i - 1];
        money = min(MAXMONEY, money);

        play_cnt += money / CAROUSEL;
        money = money % CAROUSEL;
    }

    cout << play_cnt << endl;

    return 0;
}