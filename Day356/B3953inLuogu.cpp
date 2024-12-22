/*****************************************************************
 * 题目：[GESP202403 一级] 找因数
 * 描述：找出数字的所有因数。
 * 思路：遍历一遍。
 * 对象：Factor模拟因数。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Factor
{
private:
public:
    /* 分解因数。 */
    vector<int> get_factors(int Num)
    {
        vector<int> res;
        rep(i, 1, Num)
        {
            if (Num % i == 0)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main()
{
    Factor f;
    int num;
    cin >> num;
    auto res = f.get_factors(num);

    for (auto e : res)
    {
        cout << e << endl;
    }
    return 0;
}