/*********************************************************
 * 题目：[COCI2013-2014#4] NASLJEDSTVO
 * 描述：根据平分拿走小部分剩下的个数判断总数。
 * 思路：见P8012 Solve
 * 对象：EuqalDivide模拟平分。
 * 注意：注意答案的上下界。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class EqualDivide
{
private:
public:
    /* 根据平分剩下的个数来返回总数的上下界。 */
    pair<int, int> recover(int part_num, int left_num)
    {
        int upperbound = left_num * part_num * 1.0 / (part_num - 1);
        int lowerbound = (left_num - 1) * part_num;
        if (lowerbound % (part_num - 1) == 0)
        {
            lowerbound = lowerbound / (part_num - 1) + 1;
        }
        else
        {
            lowerbound = ceil(lowerbound * 1.0 / (part_num - 1));
        }

        return make_pair(lowerbound, upperbound);
    }
};

int main()
{
    EqualDivide ed;
    int part_num, left_num;
    cin >> part_num >> left_num;

    pair<int, int> ans = ed.recover(part_num, left_num);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}
