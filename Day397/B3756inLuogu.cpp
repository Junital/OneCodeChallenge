/*****************************************************************
 * 题目：[信息与未来 2021] 幸运数字
 * 描述：统计5、7、9进制中无数字0的个数。
 * 思路：迭代取模。
 * 对象：FullyNonDivisibleByModulus模拟不被约定模数迭代整除的过滤器。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class FullyNonDivisibleByModulus
{
private:
    vector<int> Mods;

public:
    FullyNonDivisibleByModulus(vector<int> mods) : Mods(mods) {}

    // 检查数字是否不被模数整除
    bool isFullyNonDivisible(int number)
    {
        for (auto m : Mods)
        {
            int x = number;
            while (x != 0)
            {
                if (x % m == 0)
                {
                    // cout << number << " " << m << endl;
                    return false;
                }
                x /= m;
            }
        }
        return true;
    }

    // 获取范围内所有不被整除的数
    vector<int> getNumbersInRange(int start, int end)
    {
        vector<int> result;
        for (int i = start; i <= end; i++)
        {
            if (isFullyNonDivisible(i))
                result.push_back(i);
        }
        return result;
    }
};

int main()
{
    const vector<int> mods = {5, 7, 9};
    int start, end;
    cin >> start >> end;

    FullyNonDivisibleByModulus fndbm(mods);
    cout << fndbm.getNumbersInRange(start, end).size() << endl;

    // auto res = fndbm.getNumbersInRange(start, end);
    // for (auto e : res)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;

    // int query;
    // cin >> query;
    // cout << fndbm.isFullyNonDivisible(query) << endl;
    return 0;
}