/*****************************************************************
 * 题目：[COCI2011-2012#1] JABUKE
 * 描述：船有一定宽度，问需要移动多少步能接到苹果。
 * 思路：累加。
 * 对象：CatchApple模拟接苹果。
 * 注意：注意提升可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class CatchApple
{
private:
    int ColNum;
    int BoatSize;

    int get_left(int right)
    {
        return right - BoatSize + 1;
    }

    int get_right(int left)
    {
        return left + BoatSize - 1;
    }

public:
    CatchApple(int col_num, int boat_size)
        : ColNum(col_num), BoatSize(boat_size)
    {
    }

    /* 请求，输入所有苹果达到的列序号，输出船移动的最小距离。 */
    int query(vector<int> apples)
    {
        int left = 1; // 初识船在最左边。
        int right = get_right(left);

        int path = 0;
        for (auto apple : apples)
        {
            if (apple >= left && apple <= right)
            {
                continue;
            }
            else if (apple > right)
            {
                path += apple - right;
                right = apple;
                left = get_left(right);
            }
            else
            {
                path += left - apple;
                left = apple;
                right = get_right(left);
            }
        }

        return path;
    }
};

int main()
{
    int colnum, boatsize;
    cin >> colnum >> boatsize;

    CatchApple ca(colnum, boatsize);
    int apple_num;
    cin >> apple_num;

    vector<int> Apples(apple_num);
    rep(i, 0, apple_num - 1)
    {
        cin >> Apples[i];
    }

    cout << ca.query(Apples) << endl;
    return 0;
}