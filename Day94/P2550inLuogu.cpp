/***********************************************
 * 题目：[AHOI2001] 彩票摇奖
 * 描述：比对彩票有多少个在中奖号码中，得到相应的奖励。
 * 思路：set。
 * 对象：Lottery模拟彩票。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Lottery
{
private:
    set<int> RightNum;    // 中奖号码
    map<int, int> Reward; // 奖励

public:
    /* 初始化，输入一组中奖号码 */
    Lottery(vector<int> Nums)
    {
        for (auto n : Nums)
        {
            RightNum.insert(n);
        }
    }

    /* 检查中奖信息，将结果存储在奖励中。 */
    void Check(vector<int> Nums)
    {
        int reward = 0; // 记录对的号码数量
        for (auto n : Nums)
        {
            if (RightNum.count(n) > 0)
            {
                reward++;
            }
        }

        Reward[reward]++;
    }

    /* 输出目前获得的奖励。 */
    void Print()
    {
        cout << Reward[7] << " "
             << Reward[6] << " "
             << Reward[5] << " "
             << Reward[4] << " "
             << Reward[3] << " "
             << Reward[2] << " "
             << Reward[1] << endl;
    }
};

int main()
{
    const int Numbers = 7;

    int check_time;
    cin >> check_time;

    vector<int> nums(Numbers);
    rep(i, 0, Numbers - 1)
    {
        cin >> nums[i];
    }

    Lottery l(nums);

    rep(i, 1, check_time)
    {
        rep(j, 0, Numbers - 1)
        {
            cin >> nums[j];
        }
        l.Check(nums);
    }

    l.Print();

    return 0;
}
