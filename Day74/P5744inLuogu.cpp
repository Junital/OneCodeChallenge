/***********************************************
 * 题目：【深基7.习9】培训
 * 描述：输入一组同学，他们一年后成绩提高了20%。
 * 思路：数据库存储。
 * 对象：OrgStuDB模拟机构学员数据库。
 * 注意：暂时无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class OrgStuDB
{
private:
    const int FULLSCORE = 600; // 满分600分
    int StuNum;                // 学生人数

    struct Stu
    {
        string Name; // 名字
        int Old;     // 年龄
        int Score;   // 比赛成绩
    };

    vector<Stu> DB; // 存学生数据的数据库

public:
    /* 初始化，输入学生个数。 */
    OrgStuDB(int stunum) : StuNum(stunum)
    {
        rep(i, 1, StuNum)
        {
            string name;
            int old;
            int score;

            cin >> name >> old >> score;

            DB.push_back({name, old, score});
        }
    }

    /* 过一年，提升一定的成绩。 */
    void improve(double Percent)
    {
        rep(i, 0, StuNum - 1)
        {
            DB[i].Score = min(600, (int)(DB[i].Score * (1 + Percent)));
            DB[i].Old++;
        }
    }

    /* 输出结果。 */
    void print()
    {
        rep(i, 0, StuNum - 1)
        {
            cout << DB[i].Name << " " << DB[i].Old << " " << DB[i].Score << endl;
        }
    }
};

int main()
{
    int stunum;
    cin >> stunum;

    OrgStuDB osdb(stunum);

    osdb.improve(0.2);
    osdb.print();

    return 0;
}
