/*********************************************************
 * 题目：NOI
 * 描述：根据笔试、每题得分、类别、分数线判断是否加入队伍。
 * 思路：分段封装。
 * 对象：NOI模拟noi考试。
 * 注意：注意封装好。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class NOI
{
private:
    const int WriteSingleScore = 1;
    const int BounsScore = 5;
    const int Base = 50;
    int WriteScore;
    int ComputeScore;
    int Bonus;

public:
    /* 输入笔试通过题目，计算笔试分数。 */
    void write(int Num)
    {
        WriteScore = WriteSingleScore * Num;
    }

    /* 输入各个题目得分，计算机试分数。 */
    void compute(vector<int> Questions)
    {
        ComputeScore = 0;
        for (auto q : Questions)
        {
            ComputeScore += q;
        }
    }

    /* 输入是否是A类，计算bonus。 */
    void addition(bool isTypeA)
    {
        if (isTypeA)
        {
            Bonus = BounsScore;
        }
        else
        {
            Bonus = 0;
        }
    }

    /* 返回总分。 */
    int sum_up()
    {
        return Base + Bonus + WriteScore + ComputeScore;
    }
};

int main()
{
    const int QuestionNum = 6;
    int write_num;
    vector<int> questions(QuestionNum);
    int typeA;

    NOI noi;

    cin >> write_num;
    rep(i, 0, QuestionNum - 1)
    {
        cin >> questions[i];
    }
    cin >> typeA;

    noi.write(write_num);
    noi.compute(questions);
    if (typeA == 1)
    {
        noi.addition(true);
    }
    else
    {
        noi.addition(false);
    }

    ll threshold;
    cin >> threshold;

    if (noi.sum_up() >= threshold)
    {
        cout << "AKIOI" << endl;
    }
    else
    {
        cout << "AFO" << endl;
    }
    return 0;
}
