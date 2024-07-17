/***********************************************
 * 题目：取石子
 * 描述：每人拿一个石子，谁先拿完谁赢。
 * 思路：见P4702 Solve，统计总石子数奇偶即可判断。
 * 对象：FetchStone模拟取石子。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class FetchStone
{
private:
    int StoneNum;
    bool FirstWin;

public:
    /* 初始化，输入石子个数。 */
    FetchStone(int stonenum) : StoneNum(stonenum)
    {
        int StoneSum = 0;
        rep(i, 1, StoneNum)
        {
            int stone;
            cin >> stone;
            StoneSum += stone;
        }

        FirstWin = (StoneSum % 2 != 0);
    }

    /* 是否是先手赢。 */
    bool isFirstWinner()
    {
        return FirstWin;
    }
};

int main()
{
    int stonenum;
    cin >> stonenum;

    FetchStone fs(stonenum);

    if (fs.isFirstWinner())
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }

    return 0;
}
