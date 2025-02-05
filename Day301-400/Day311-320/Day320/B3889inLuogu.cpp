/*****************************************************************
 * 题目：[语言月赛 202311] 式神考核
 * 描述：知道总分和满分数量，计算附加分和一半分的题目。
 * 思路：通过凑数解决问题。
 * 对象：ShikigamiExam模拟式神考试。
 * 注意：注意精度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ShikigamiExam
{
public:
    /* 输入题目数量、总分、非满分。 */
    void query(int ProblemNum, int Total, int NonFull)
    {
        int Full = ProblemNum - NonFull;
        double full_score = 1.0 * Full / ProblemNum * 1e7;

        rep(i, 0, NonFull)
        {
            double half_score = 0.5 * i / ProblemNum * 1e7;
            double x = Total - full_score - half_score;
            int Plus;

            if (ceil(x) == floor(x))
            {
                Plus = x;
            }
            else
            {
                Plus = ceil(x);
            }

            if (Plus <= Full && Plus >= 0)
            {
                cout << "p" << Full << "(+" << Plus << ") f"
                     << i << " l" << NonFull - i << endl;
                return;
            }
        }
    }
};

int main()
{
    ShikigamiExam se;
    int problem_num, total, non_full;
    cin >> problem_num >> total >> non_full;

    se.query(problem_num, total, non_full);
    return 0;
}
