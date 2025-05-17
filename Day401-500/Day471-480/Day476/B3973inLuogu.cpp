/*****************************************************************
 * 题目：[语言月赛 202405] 小 S 大战小 Q
 * 描述：根据比分获取最后的赢家。
 * 思路：存储有点太浪费空间吧。
 * 对象：CompeResult模拟比赛结果统计。
 * 注意：小心空间别溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
    /* 四舍五入 */
    int Approximate(double Num)
    {
        double Ceil = ceil(Num);
        double Floor = floor(Num);

        if (Ceil - Num <= Num - Floor)
        {
            return (int)Ceil;
        }
        else
        {
            return (int)Floor;
        }
    }
};

using namespace Tools;

class CompeResult
{
private:
    vector<int> PlayerA;
    vector<int> PlayerB;

    int CompeNum; // 比赛场数

public:
    /* 初始化 */
    CompeResult(int num) : CompeNum(num) {}

    /* 获取A分数。 */
    void input_A()
    {
        PlayerA.resize(CompeNum);
        for (int i = 0; i < CompeNum; i++)
        {
            cin >> PlayerA[i];
        }
    }

    /* 获取B分数。 */
    void input_B()
    {
        PlayerB.resize(CompeNum);
        for (int i = 0; i < CompeNum; i++)
        {
            cin >> PlayerB[i];
        }
    }

    /* 获取胜场，输出pair<A胜场, B胜场>。 */
    pair<int, int> get_win()
    {
        if (PlayerA.size() != PlayerB.size())
        {
            throw runtime_error("The score lengths of two players must be the same.");
        }

        int A_win = 0, B_win = 0;
        for (int i = 0; i < CompeNum; i++)
        {
            if (PlayerA[i] > PlayerB[i])
            {
                A_win++;
            }
            else if (PlayerB[i] > PlayerA[i])
            {
                B_win++;
            }
        }

        return make_pair(A_win, B_win);
    }
};

int main()
{
    int size;
    cin >> size;
    CompeResult cr(size);

    cr.input_A();
    cr.input_B();

    auto result = cr.get_win();

    cout << result.first << " " << result.second << endl;

    if (result.first > result.second)
    {
        cout << "S" << endl;
    }
    else if (result.first < result.second)
    {
        cout << "Q" << endl;
    }
    else
    {
        cout << "Tie" << endl;
    }
    return 0;
}