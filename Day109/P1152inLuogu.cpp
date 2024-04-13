/***********************************************
 * 题目：欢乐的跳
 * 描述：两个台阶之间的差值必须包括所有可能。
 * 思路：统计。
 * 对象：HappyJump模拟。
 * 注意：时间问题，不知道是否会出问题。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class HappyJump
{
private:
    int SeqLen;        // 序列长度
    vector<int> Steps; // 台阶
    set<int> Diff;     // 台阶的差值

public:
    /* 初始化，输入序列长度。 */
    HappyJump(int len) : SeqLen(len)
    {
        Steps.resize(SeqLen);
        rep(i, 0, SeqLen - 1)
        {
            cin >> Steps[i];
        }
    }

    /* 判断是否是快乐的跳。 */
    bool Judge()
    {
        rep(i, 1, SeqLen - 1)
        {
            Diff.insert(abs(Steps[i] - Steps[i - 1]));
        }

        rep(i, 1, SeqLen - 1)
        {
            if (Diff.count(i) == 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    int len;
    cin >> len;

    HappyJump hj(len);

    if (hj.Judge())
    {
        cout << "Jolly" << endl;
    }
    else
    {
        cout << "Not jolly" << endl;
    }
    return 0;
}
