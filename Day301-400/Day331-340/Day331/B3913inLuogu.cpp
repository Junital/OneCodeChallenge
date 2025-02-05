/*****************************************************************
 * 题目：[语言月赛 202401] 装满葡萄汁的酒杯
 * 描述：选择合适的酒杯，能装下一定容量的葡萄汁。
 * 思路：lower_bound函数。
 * 对象：CupChoice模拟选择酒杯。
 * 注意：注意特殊情况。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class CupChoice
{
private:
    set<int> Cups; // 酒杯

public:
    /* 初始化，输入酒杯数组。 */
    CupChoice(vector<int> cups) : Cups(cups.begin(), cups.end()) {}

    /* 请求，输入容量，输出合适的酒杯容量。 */
    int query(int vol)
    {
        auto it = Cups.lower_bound(vol);
        if (it != Cups.end())
        {
            return *it;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    const vector<int> cups = {100,
                              150,
                              300,
                              400,
                              1000};

    CupChoice cc(cups);

    int vol;
    cin >> vol;

    cout << cc.query(vol) << endl;
    return 0;
}