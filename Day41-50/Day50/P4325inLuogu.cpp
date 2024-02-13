/***********************************************
 * 题目：[COCI2006-2007#1] Modulo
 * 描述：10个整数中，整除42余数的情况。
 * 思路：统计。
 * 对象：MagicFortyOne模拟。
 * 注意：整除情况需要考虑。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义长整型

class MagicFortyOne
{
private:
    const int Num = 10;         // 只需要输入10个数字
    map<int, int> RemainderCnt; // 统计余数的个数

public:
    /* 初始化，输入10个数字。 */
    MagicFortyOne()
    {
        rep(i, 1, Num)
        {
            int x;
            cin >> x;
            int Remain = x % 42;
            RemainderCnt[Remain]++;
        }
    }

    /* 得到余数的种类。 */
    int getRemainNum()
    {
        return RemainderCnt.size();
    }
};

int main()
{
    MagicFortyOne mfo;

    cout << mfo.getRemainNum() << endl;
    return 0;
}