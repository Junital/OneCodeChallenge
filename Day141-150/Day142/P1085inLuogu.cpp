/******************************************************
 * 题目：不高兴的津津
 * 描述：不积累的不高兴。
 * 求出最不高兴的一天。
 * 思路：模拟即可。
 * 对象：Unhappy计算不开心。
 ******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速循环

class Unhappy
{
private:
    const int UNHPYTHRES = 8; // 不开心阈值

public:
    /* 输入一个元素为两个整型的数组，输出计算得到的最不开心对应的编号。 */
    int MaxUnhappy(vector<pair<int, int>> Schedule)
    {
        int Unhappy = 0;              // 初始不开心值为0
        int MaxUnhpy = -1;            // 最大不开心值
        int MaxUnhpyIdx = -1;         // 最大不开心值序号
        int DayNum = Schedule.size(); // 天数

        rep(i, 0, DayNum - 1)
        {
            pair<int, int> DaySched = Schedule[i];
            int ClassSched = DaySched.first;                    // 获得上课时间
            int ExtracuSched = DaySched.second;                 // 获得补习班时间
            Unhappy = (ClassSched + ExtracuSched) - UNHPYTHRES; // 迭代计算每天的不开心程度
            if (Unhappy > 0 && Unhappy > MaxUnhpy)
            {
                MaxUnhpy = Unhappy;
                MaxUnhpyIdx = i;
            }
        }

        return MaxUnhpyIdx;
    }
};

int main()
{
    int SchedSize = 7;               // 一共有几天
    vector<pair<int, int>> Schedule; // 每个元素为（上学时间，课外补习时间）二元组
    Unhappy unhpy;

    rep(i, 1, SchedSize)
    {
        int ClassSched;
        int ExtracuSched;
        cin >> ClassSched >> ExtracuSched;
        Schedule.push_back(make_pair(ClassSched, ExtracuSched));
    }

    cout << unhpy.MaxUnhappy(Schedule) + 1 << endl;
    return 0;
}
