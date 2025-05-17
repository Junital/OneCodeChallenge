/*****************************************************************
 * 题目：[语言月赛 202404] ZngivaeL 的中考
 * 描述：根据每门考试成绩等级决定上什么高中。
 * 思路：直接判断。
 * 空间：GradeAssistant模拟成绩助手。
 * 注意：输出格式要注意。
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

namespace GradeAssistant
{
    /* 与其他类不同，专门用于统计一个班级的分数。 */
    class ClassScore
    {
    private:
        vector<vector<int>> Students;
        int StuNum;
        int SubjectNum;
        vector<double> AvgScores;

        const int SinSubThres = 5;  // 单科成绩分差不超过5（用于比较差距）
        const int TotSubThres = 10; // 全科成绩分差不超过10（用于比较差距）

        void getAvgScores()
        {
            AvgScores.clear();

            for (int j = 0; j < SubjectNum; j++)
            {
                double avg = 0;
                for (int i = 0; i < StuNum; i++)
                {
                    avg += Students[i][j];
                }
                avg /= StuNum;
                AvgScores.push_back(avg);
            }
        }

    public:
        /* 初始化，输入一个班级的分数。 */
        ClassScore(vector<vector<int>> students) : Students(students)
        {
            StuNum = Students.size();
            SubjectNum = Students[0].size();
            for (auto s : Students)
            {
                assert((int)s.size() == SubjectNum);
            }

            // 计算平均分数。
            getAvgScores();
        }

        /* 获得旗鼓相当的对手数 */
        int getOpponentsNum()
        {
            /* 思路：逐个比较，看成绩是否满足一定范围内。 */
            int OpponentsNum = 0; // 记录对手数

            rep(i, 0, StuNum - 1)
            {
                rep(j, i + 1, StuNum - 1)
                {
                    bool SinSatisfy = true; // 单科成绩是否满足
                    int iScoreSum = 0;      // i的成绩之和
                    int jScoreSum = 0;      // j的成绩之和
                    rep(k, 0, SubjectNum - 1)
                    {
                        if (abs(Students[i][k] - Students[j][k]) > SinSubThres)
                        {
                            SinSatisfy = false;
                            break;
                        }
                        iScoreSum += Students[i][k];
                        jScoreSum += Students[j][k];
                    }

                    if (SinSatisfy)
                    {
                        if (abs(iScoreSum - jScoreSum) <= TotSubThres)
                        {
                            OpponentsNum++;
                        }
                    }
                }
            }
            return OpponentsNum;
        }

        /* 输出每个学生的中上游门数。 */
        vector<int> getOverAvgNum()
        {
            vector<int> res;

            for (int i = 0; i < StuNum; i++)
            {
                int count = 0;
                for (int j = 0; j < SubjectNum; j++)
                {
                    if (Students[i][j] >= AvgScores[j])
                    {
                        count++;
                    }
                }

                res.push_back(count);
            }

            return res;
        }
    };

    /* 计算综合成绩 */
    class ScoreModel
    {
    private:
        ll FullScoreSum; // 各科满分总和
        ll SelfScoreSum; // 个人成绩总分

    public:
        /* 初始化，输入科目数量。 */
        ScoreModel(int SubNum)
        {
            FullScoreSum = 0;
            SelfScoreSum = 0;

            rep(i, 1, SubNum)
            {
                ll score;
                cin >> score;
                FullScoreSum += score;
            }

            rep(i, 1, SubNum)
            {
                ll score;
                cin >> score;
                SelfScoreSum += score;
            }
        }

        /* 空构造器。 */
        ScoreModel() {}

        /* 获得综合分数，适用于已经在构造的时候已经有成绩了。 */
        double getAggreScore()
        {
            assert(FullScoreSum != 0 && SelfScoreSum != 0);
            ll LackScoreSum = FullScoreSum - SelfScoreSum;

            double top = FullScoreSum * 3 - SelfScoreSum * 2;

            return top / LackScoreSum;
        }

        /* 判断不及格的科目是否小于等于阈值。 */
        bool JudgeFailNum(vector<int> Scores, int PassLine, int Threshold)
        {
            int fail_num = 0; // 不及格数量
            for (auto s : Scores)
            {
                if (s < PassLine)
                {
                    fail_num++;
                }
            }

            return fail_num <= Threshold;
        }

        /* 计算加权平均分。 */
        double WeightedScore(vector<int> Scores, vector<double> Weights)
        {
            assert(Scores.size() == Weights.size());

            int LessonNum = Scores.size();
            double FinalScore = 0;
            double WeightSum = 0;

            rep(i, 0, LessonNum - 1)
            {
                FinalScore += Scores[i] * Weights[i];
                WeightSum += Weights[i];
            }

            return FinalScore / WeightSum;
        }
    };

    /* 计算单科期末成绩 */
    class SubjectScore
    {
    private:
        double HomeworkRate; // 作业成绩占比
        double TestRate;     // 测试成绩占比
        double ExamRate;     // 考试成绩占比

    public:
        /* 初始化，输入作业成绩占比、测试成绩占比、考试成绩占比。 */
        SubjectScore(double homework, double test, double exam)
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

    /* 计算GPA分数。 */
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

    /* 高中录取判断。 */
    class AdmissionJudgement
    {
    private:
        const set<char> RatingSet = {'A', 'B', 'C', 'D'};

        // 重点高中。
        bool judge_key_high_school(const string &ratings)
        {
            bool hasA = false;
            for (char rating : ratings)
            {
                if (rating == 'A')
                {
                    hasA = true;
                }
                else if (rating > 'B')
                {
                    return false;
                }
            }
            return hasA;
        }

        // 普通高中
        bool judge_normal_high_school(const string &ratings)
        {
            for (char rating : ratings)
            {
                if (rating > 'C')
                {
                    return false;
                }
            }
            return true;
        }

    public:
        // 根据评级判断能上的最高难度高中
        string getAdmissionResult(const std::string &ratings)
        {
            for (auto ch : ratings)
            {
                if (!RatingSet.count(ch))
                {
                    throw invalid_argument("The rating must be among A, B, C and D.");
                }
            }

            if (judge_key_high_school(ratings))
            {
                return "I'm so happy.";
            }
            else if (judge_normal_high_school(ratings))
            {
                return "This is ok.";
            }
            return "Never give up.";
        }
    };
};

using namespace GradeAssistant;

int main()
{
    AdmissionJudgement aj;

    string ratings;
    cin >> ratings;

    cout << aj.getAdmissionResult(ratings) << endl;
    return 0;
}