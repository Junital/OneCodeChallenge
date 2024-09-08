/*****************************************************************
 * 题目：[蓝桥杯 2013 省 AB] 错误票据
 * 描述：找到断号与重号。
 * 思路：统计26个字母。
 * 对象：BrokenDouble模拟断号与连号。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class BrokenDouble
{
private:
public:
    /* 找到断号与重号。 */
    pair<int, int> find(vector<int> Arr)
    {
        map<int, int> IDs;
        for (auto element : Arr)
        {
            IDs[element]++;
        }

        int broken_id = 0, double_id = 0;

        int it = IDs.begin()->first;
        bool end_flag = false;
        while (!end_flag)
        {
            if (IDs[it] == 0)
            {
                broken_id = it;
            }
            if (IDs[it] > 1)
            {
                double_id = it;
            }

            if (broken_id != 0 && double_id != 0)
            {
                end_flag = true;
            }

            it++;
        }

        return make_pair(broken_id, double_id);
    }
};

int main()
{
    BrokenDouble bd;
    int input_size;
    cin >> input_size;
    vector<string> input(input_size);

    getline(cin, input[0]); // 消除第一行
    rep(i, 0, input_size - 1)
    {
        // cout << i << endl;
        getline(cin, input[i]);
    }

    vector<int> Arr;

    for (auto str : input)
    {
        istringstream stream(str);

        int num;
        while (stream >> num)
        {
            // cout << num << endl;
            Arr.push_back(num);
        }
    }

    auto res = bd.find(Arr);
    cout << res.first << " " << res.second << endl;

    return 0;
}
