/*****************************************************************
 * 题目：[传智杯 #4 初赛] 报告赋分
 * 描述：页数超过最大页数每次扣一分，少于最少页数扣10分。
 * 思路：简单判断。
 * 对象：ReportScore模拟报告分数。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ReportScore
{
private:
    int MinPage;  // 最少页数
    int MaxPage;  // 最多页数
    int LessLoss; // 少扣的分
    int MoreLoss; // 多扣的分

public:
    ReportScore(int min_page, int max_page,
                int less_loss, int more_loss)
        : MinPage(min_page), MaxPage(max_page),
          LessLoss(less_loss), MoreLoss(more_loss) {}

    /* 计算，输入基础分和页数。 */
    int calculate(int BaseScore, int PageNum)
    {
        int Score = BaseScore;
        if (PageNum > MaxPage)
        {
            Score = max(0, Score - (PageNum - MaxPage) * MoreLoss);
        }
        if (PageNum < MinPage)
        {
            Score = max(0, Score - LessLoss);
        }

        return Score;
    }
};

int main()
{
    const int min_page = 16;
    const int max_page = 20;
    const int less_loss = 10;
    const int more_loss = 1;
    ReportScore rs(min_page, max_page, less_loss, more_loss);

    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        int base_score, page_num;
        cin >> base_score >> page_num;

        cout << rs.calculate(base_score, page_num) << endl;
    }
    return 0;
}
