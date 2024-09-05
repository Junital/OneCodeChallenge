/*****************************************************************
 * 题目：Water
 * 描述：输入不超过某个阈值的倍数。
 * 思路：用floor进行计算。
 * 对象：ThresholdMultiple模拟阈值之内的倍数。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long // 定义长整型

class ThresholdMultiple
{
private:
public:
    ll Maximize(ll Threshold, ll Base, ll ActionNum)
    {
        ll Times = min(Threshold / Base, ActionNum);
        return Times * Base;
    }
};

int main()
{
    ThresholdMultiple tm;
    ll thres, base, action_num;
    cin >> thres >> base >> action_num;

    cout << tm.Maximize(thres, base, action_num) << endl;
    return 0;
}
