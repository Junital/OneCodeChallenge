/*****************************************************************
 * 题目：统计满足条件的 4 位数
 * 描述：判断四位数是否满足个位减去其他三位大于0。
 * 思路：转化成字符串，再进行判断。
 * 对象：SpecialFourDigits模拟特殊四位数。
 * 注意：注意加入可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class SpecialFourDigits
{
private:
    const int Limit = 4;

    int convert(char ch)
    {
        return ch - '0';
    }

public:
    /* 判断个位数减去其他三位数是否大于0 */
    bool judge_lastminusotherslargerthan0(int Num)
    {
        string str = to_string(Num);
        assert(str.size() == Limit);

        return (convert(str[3]) - convert(str[2]) -
                convert(str[1]) - convert(str[0])) > 0;
    }
};

int main()
{
    int total;
    SpecialFourDigits sfd;
    cin >> total;

    int res = 0;
    rep(i, 1, total)
    {
        int num;
        cin >> num;
        if (sfd.judge_lastminusotherslargerthan0(num))
        {
            res++;
        }
    }

    cout << res << endl;
    return 0;
}
