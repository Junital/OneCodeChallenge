/*****************************************************************
 * 题目：[语言月赛 202402] 分配工资
 * 描述：每个人干的工作不同，每个工作有对应的分成，问某个人应该拿多少。
 * 思路：用map来分配。
 * 对象：SalaryAssignment模拟工资分配。
 * 注意：注意数据精度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class SalaryAssginment
{
private:
    double AllSalary;
    int TotalPart;
    map<int, int> ID2Part;

public:
    /* 初始化，输入工资总数，以及每项工作的负责人和分红。 */
    SalaryAssginment(double all_salary, vector<pair<int, int>> Tasks)
        : AllSalary(all_salary)
    {
        TotalPart = 0;
        for (auto task : Tasks)
        {
            ID2Part[task.first] += task.second;
            TotalPart += task.second;
        }
    }

    /* 请求某个员工的工资。 */
    double get_salary(int ID)
    {
        double Part = ID2Part[ID];
        return AllSalary * (Part / TotalPart);
    }
};

int main()
{
    int RatRaceKingID = 1;
    int size, all_salary;
    cin >> size >> all_salary;

    vector<pair<int, int>> tasks(size);

    rep(i, 0, size - 1)
    {
        cin >> tasks[i].first >> tasks[i].second;
    }

    SalaryAssginment sa(all_salary, tasks);

    cout << fixed << setprecision(3) << sa.get_salary(RatRaceKingID) << endl;
    return 0;
}