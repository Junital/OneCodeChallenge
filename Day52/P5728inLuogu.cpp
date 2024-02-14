/***********************************************
 * 题目：【深基5.例5】旗鼓相当的对手
 * 描述：给出每个人的成绩，找出每科成绩相差<=5的旗鼓相当的对手。
 * 思路：简单统计。
 * 对象：EqualOpponent模拟旗鼓相当的对手。
 * 注意：把所有组合都遍历到。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速定义循环

/* 用来帮你找到旗鼓相当的对手 */
class EqualOpponent
{
private:
    const int SubjectNum = 3;     // 科目数量
    int StuNum;                   // 学生的个数
    const int SinSubThres = 5;    // 单科成绩分差不超过5
    const int TotSubThres = 10;   // 全科成绩分差不超过10
    vector<vector<int>> Students; // 每一行代表学生的各科分数

public:
    /* 初始化对象，需要输入有几个学生。 */
    EqualOpponent(int sn) : StuNum(sn)
    {
        /* 初始化数组 */
        Students.resize(StuNum);
        rep(i, 0, StuNum - 1)
        {
            Students[i].resize(SubjectNum);
        }

        /* 输入成绩 */
        rep(i, 0, StuNum - 1)
        {
            rep(j, 0, SubjectNum - 1)
            {
                cin >> Students[i][j];
            }
        }
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
};

int main()
{
    int StuNum;
    cin >> StuNum;

    EqualOpponent eo(StuNum);

    cout << eo.getOpponentsNum() << endl;
}
