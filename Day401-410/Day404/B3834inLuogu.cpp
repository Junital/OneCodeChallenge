/*****************************************************************
 * 题目：[GESP202303 一级] 长方形面积
 * 描述：给定特定面积，问有几种长方形。
 * 思路：遍历。
 * 对象：Factor模拟因数。
 * 注意：数据范围和时间复杂度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Factor
{
private:
public:
    /* 分解因数。 */
    vector<int> get_factors(int Num)
    {
        vector<int> res;
        for (int i = 1; i <= Num; i++)
        {
            if (Num % i == 0)
            {
                res.push_back(i);
            }
        }

        return res;
    }

    /* 分解因数配对。 */
    vector<pair<int, int>> get_factor_pairs(int Num)
    {
        vector<pair<int, int>> res;
        for (int i = 1; i <= (int)sqrt(Num); i++)
        {
            if (Num % i == 0)
            {
                res.push_back(make_pair(i, Num / i));
            }
        }

        return res;
    }
};

int main()
{
    int num;
    Factor f;

    cin >> num;
    cout << f.get_factor_pairs(num).size() << endl;
    return 0;
}
