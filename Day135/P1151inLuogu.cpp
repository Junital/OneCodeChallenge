/***************************************************************
 * 题目：子数整数。
 * 描述：求出三个子数，并都可被某个数同时整除。
 * 思路：模拟。
 * 对象：SubNum模拟子数。
 * 注意：无。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class SubNum
{
private:
    const int SubDigit = 3;

public:
    /* 输入一个数字，给出一个子数数组。 */
    vector<int> getSubNum(int Num)
    {
        vector<int> Sub;

        int mod = pow(10, SubDigit);
        while (Num >= 100)
        {
            Sub.push_back(Num % mod);
            Num /= 10;
        }

        return Sub;
    }

    /* 给定一个模数和寻找数的范围，求出满足子数都被模数整除的整数。 */
    vector<int> findSubNum(int Mod, int Start, int End)
    {
        vector<int> Ans; // 存储满足的整数

        rep(i, Start, End)
        {
            vector<int> Sub = getSubNum(i);
            bool all_satisfy = true;

            for (auto s : Sub)
            {
                if (s % Mod != 0)
                {
                    all_satisfy = false;
                    break;
                }
            }

            if (all_satisfy)
            {
                Ans.push_back(i);
            }
        }

        return Ans;
    }
};

int main()
{
    SubNum sn;
    int mod;

    cin >> mod;
    vector<int> ans = sn.findSubNum(mod, 10000, 30000);

    if (ans.size() == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        for (auto a : ans)
        {
            cout << a << endl;
        }
    }
    return 0;
}
