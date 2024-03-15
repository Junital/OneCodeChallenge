/***********************************************
 * 题目：【深基4.例4】一尺之棰
 * 描述：输入一个木棍长度，输出需要几次折半才能使其长度为1。
 * 思路：见Solve.png，打算先初始化。
 * 对象：HalfRod模拟木棍折半。
 * 注意：理论上应该内存应该不会爆炸。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

/* 测试一下内存是否会爆炸。 */
void test()
{
    int i = 1;
    int cnt = 1;

    while (i <= 1e9)
    {
        i *= 2;
        cnt++;
    }

    cout << cnt << endl;
}

/* 模拟木棍，每次锯掉一半。 */
class HalfRod
{
private:
    int RodLen; // 木棍长度

    /* 计算需要切几次。 */
    void calCutTimes()
    {
        CutTimes = 1;

        while (RodLen != 1)
        {
            CutTimes++;
            RodLen >>= 1;
        }
    }

public:
    int CutTimes;

    /* 初始化，输入木棍长度。 */
    HalfRod(int rodlen) : RodLen(rodlen)
    {
        calCutTimes();
    }
};

int main()
{
    int rodlen;

    cin >> rodlen;

    HalfRod hr(rodlen);

    cout << hr.CutTimes << endl;
    return 0;
}