/*****************************************************************
 * 题目：[语言月赛 202309] 打水赛打的
 * 描述：筛选所有满足条件的元素。
 * 思路：set封装，判断是否存在。
 * 空间：Tools模拟常用工具。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

int main()
{
    const int threshold = 200;

    int score_num, winner_num;
    cin >> score_num >> winner_num;

    vector<int> scores(score_num);
    rep(i, 0, score_num - 1)
    {
        cin >> scores[i];
    }

    set<int> winners;
    rep(i, 1, winner_num)
    {
        int win;
        cin >> win;
        winners.insert(win);
    }

    int count = 0;
    rep(i, 0, score_num - 1)
    {
        if (scores[i] < threshold && winners.count(i + 1) > 0)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}