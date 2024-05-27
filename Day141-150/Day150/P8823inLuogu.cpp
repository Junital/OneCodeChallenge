/**********************************************************
 * 题目：[传智杯 #3 初赛] 期末考试成绩
 * 描述：计算GPA成绩。
 * 思路：分段考虑。
 * 对象：GPA模拟计算成绩。
 * 注意：要考虑所有情况。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class GPA
{
private:
    double FullScore; // 满分
    int FullLimit;    // 满分线
    int ZeroThres;    // 零分阈值
    double Decrease;  // 满分线下每分下降的GPA

public:
    /* 初始化，输入满分、满分线、零分阈值，下降速度。 */
    GPA(double fullscore, int fulllimit, int zerothres, double decrease)
        : FullScore(fullscore), FullLimit(fulllimit),
          ZeroThres(zerothres), Decrease(decrease)
    {
    }

    /* 计算成绩，支持是否捞一下不及格的。 */
    double getScore(int Exam, bool Save = false)
    {
        if (Exam >= FullLimit)
        {
            return FullScore;
        }

        if (Exam < ZeroThres && Save)
        {
            Exam = sqrt(Exam) * 10.0;
        }

        if (Exam >= ZeroThres)
        {
            return FullScore - Decrease * (FullLimit - Exam);
        }

        return 0;
    }
};

int main()
{
    GPA gpa(4.0, 90, 60, 0.1); // 目前任务的参数

    int exam;
    cin >> exam;

    cout << fixed << setprecision(1) << gpa.getScore(exam, true) << endl;
    return 0;
}
