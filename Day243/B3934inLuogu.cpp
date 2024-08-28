/*****************************************************************
 * 题目：[语言月赛 202402] 三位数
 * 描述：满足前两位、后两位和三位数都能整除某个数，输出多个可能的结果。
 * 思路：遍历迭代。
 * 对象：PerfectTripleNum模拟完美三位数。
 * 注意：注意保持可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class PerfectTripleNum
{
private:
public:
    bool run(int Mod)
    {
        bool Exists = false;
        rep(A, 1, 9)
        {
            rep(B, 0, 9)
            {
                rep(C, 0, 9)
                {
                    if ((A * 10 + B) % Mod == 0 &&
                        (B * 10 + C) % Mod == 0 &&
                        (A * 100 + B * 10 + C) % Mod == 0)
                    {
                        Exists = true;
                        cout << A * 100 + B * 10 + C << endl;
                    }
                }
            }
        }
        return Exists;
    }
};

int main()
{
    PerfectTripleNum ptn;
    int mod;
    cin >> mod;

    if (!ptn.run(mod))
    {
        cout << "None!" << endl;
    }
    return 0;
}