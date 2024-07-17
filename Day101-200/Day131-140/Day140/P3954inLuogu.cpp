/***************************************************************
 * 题目：[NOIP2017 普及组] 成绩
 * 描述：根据作业成绩、小测成绩和期末成绩计算总分。
 * 思路：数学计算。
 * 对象：ClassScore计算成绩。
 * 注意：保证精度。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ClassScore
{
private:
    double HomeworkRate; // 作业成绩占比
    double TestRate;     // 测试成绩占比
    double ExamRate;     // 考试成绩占比

public:
    /* 初始化，输入作业成绩占比、测试成绩占比、考试成绩占比。 */
    ClassScore(double homework, double test, double exam)
        : HomeworkRate(homework), TestRate(test), ExamRate(exam)
    {
        assert(HomeworkRate + TestRate + ExamRate == 1);
    }

    /* 输入学生的各方面成绩，得到综合成绩。 */
    int getScore(int Homework, int Test, int Exam)
    {
        return Homework * HomeworkRate + Test * TestRate + Exam * ExamRate;
    }
};

int main()
{
    ClassScore cpp(0.2, 0.3, 0.5);

    int homework, test, exam;

    cin >> homework >> test >> exam;
    cout << cpp.getScore(homework, test, exam) << endl;

    return 0;
}