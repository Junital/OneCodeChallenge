/***********************************************
 * 题目：【深基15.例1】询问学号
 * 描述：询问n个学生的学号。
 * 思路：访问数组。
 * 对象：StuID模拟学号。
 * 注意：数组大小不要超了。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class StuID
{
private:
    vector<int> ID; // 学生的学号
    int StuNum;     // 学生人数

public:
    /* 初始化，输入学生人数。 */
    StuID(int stunum) : StuNum(stunum)
    {
        rep(i, 0, StuNum - 1)
        {
            int id;
            cin >> id;
            ID.push_back(id);
        }
    }

    /* 查询学号。 */
    int query(int idx)
    {
        return ID[idx - 1];
    }
};

int main()
{
    int stunum;
    int querynum;

    cin >> stunum >> querynum;

    StuID si(stunum);

    rep(i, 1, querynum)
    {
        int queryid;
        cin >> queryid;

        cout << si.query(queryid) << endl;
    }
}