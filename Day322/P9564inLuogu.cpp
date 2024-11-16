/*****************************************************************
 * 题目：[SDCPC2023] Three Dice
 * 描述：骰子有红色和黑色之分，求三个骰子能否投出红色点为x，黑色点为y的情况。
 * 思路：遍历所有情况，将所有可能存储。
 * 对象：ColoredDice模拟带颜色的骰子。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ColoredDice
{
private:
    const string RED = "Red";
    const string BLACK = "Black";

    const map<int, string> Color = {
        {1, RED},
        {2, BLACK},
        {3, BLACK},
        {4, RED},
        {5, BLACK},
        {6, BLACK}};

    int DiceNum; // 骰子数量

    struct Result
    {
        int Red, Black;

        bool operator<(const Result &other) const
        {
            if (this->Red != other.Red)
            {
                return this->Red < other.Red;
            }
            return this->Black < other.Black;
        }

        Result(int r, int b) : Red(r), Black(b) {}
    };

    set<Result> PossibleAns; // 可能的结果

    /* 初始化，构造可能的所有结果。 */
    void init()
    {
        queue<Result> q;
        q.push({0, 0});

        rep(i, 1, DiceNum)
        {
            set<Result> ResSet;
            while (!q.empty())
            {
                Result res = q.front();
                // cout << "top: " << res.Red << " " << res.Black << endl;
                q.pop();
                rep(j, 1, 6)
                {
                    auto it = Color.find(j);
                    assert(it != Color.end());

                    string color = it->second;
                    assert(color == RED || color == BLACK);

                    if (color == RED)
                    {
                        ResSet.insert({res.Red + j, res.Black});
                    }
                    else if (color == BLACK)
                    {
                        ResSet.insert({res.Red, res.Black + j});
                    }
                }
            }

            if (i == DiceNum)
            {
                PossibleAns = ResSet;
                // for (auto pa : PossibleAns)
                // {
                //     cout << pa.Red << " " << pa.Black << "  ";
                // }
                // cout << endl;
                return;
            }

            for (auto p : ResSet)
            {
                // cout << p.Red << " " << p.Black << " ";
                q.push(p);
            }
            // cout << endl;
        }
    }

public:
    /* 初始化，输入骰子数量。 */
    ColoredDice(int dice_num) : DiceNum(dice_num)
    {
        init();
    }

    /* 请求，输入一种可能，判断是否存在。 */
    bool query(int Red, int Black)
    {
        Result r = {Red, Black};
        // cout << PossibleAns.count(r) << endl;
        return PossibleAns.count(r) > 0;
    }
};

int main()
{
    const int dice_num = 3;
    ColoredDice cd(dice_num);

    int red, black;
    cin >> red >> black;

    if (cd.query(red, black))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}