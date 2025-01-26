/*********************************************
 * 题目：[THUPC2025 初赛] 好成绩
 * 描述：根据取模线索，计算成绩。
 * 思路：逐一遍历。
 * 对象：MultiMod模拟多个取模找数。
 * 注意：注意提高可拓展性。
 ********************************************/

#include <bits/stdc++.h>

using namespace std;

struct ModRemainder
{
    int mod;
    int remainder;
};

class MultiMod
{
private:
    vector<ModRemainder> MRs; // 模数与余数。

public:
    MultiMod(vector<ModRemainder> mrs) : MRs(mrs) {}

    bool satisfy(int Num)
    {
        for (auto mr : MRs)
        {
            if (Num % mr.mod != mr.remainder)
            {
                return false;
            }
        }
        return true;
    }

    /* 区间查询，返回可能的值。 */
    vector<int> query(int Begin, int End)
    {
        vector<int> res;

        for (int i = Begin; i <= End; i++)
        {
            if (satisfy(i))
            {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main()
{
    const vector<ModRemainder> mrs = {
        {3, 2},
        {5, 3},
        {7, 6}};

    MultiMod mm(mrs);

    cout << mm.query(0, 150)[0] << endl;
    return 0;
}