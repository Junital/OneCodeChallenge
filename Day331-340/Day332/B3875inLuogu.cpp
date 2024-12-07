/*****************************************************************
 * 题目：[信息与未来 2015] 夏令营小旗手
 * 描述：根据递推式计算每个人投的那个人，计算得到最后的获胜者。
 * 思路：模拟，max_element。
 * 对象：SummerCampVoter模拟夏令营投票。
 * 注意：注意索引变换。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class SummerCampVoter
{
private:
    vector<int> Students; // 学生

    int get_next(int last)
    {
        int stunum = Students.size();

        return (last * 37 + 33031) % stunum + 1;
    }

public:
    /* 初始化，输入学生数量。 */
    SummerCampVoter(int StuNum)
    {
        Students.resize(StuNum, 0);
    }

    /* 进行投票，输入初始值，进行循环模拟。 */
    int vote(int Init)
    {
        Students[Init - 1]++;

        int last = Init;
        int stusize = Students.size();
        rep(i, 1, stusize - 1)
        {
            last = get_next(last);
            Students[last - 1]++;
        }

        int winner = max_element(Students.begin(), Students.end()) -
                     Students.begin();
        return winner + 1;
    }
};

int main()
{
    int stu_num, init;
    cin >> stu_num >> init;

    SummerCampVoter scv(stu_num);
    cout << scv.vote(init) << endl;

    return 0;
}