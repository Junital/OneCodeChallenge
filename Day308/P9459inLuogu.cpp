/*****************************************************************
 * 题目：「EZEC-14」浴眼盯真
 * 描述：判断满不满足y_ y_ ding zhen。
 * 思路：判断，
 * 对象：YYDingZhen模拟一眼丁真。
 * 注意：适量玩梗。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class YYDingZhen
{
private:
public:
    /* 输入四个字符串进行判断。 */
    bool judge(string a, string b, string c, string d)
    {
        if (a.length() < 1 || b.length() < 1)
        {
            return false;
        }

        return a[0] == 'y' && b[0] == 'y' &&
               c == "ding" && d == "zhen";
    }
};

int main()
{
    YYDingZhen yydz;
    int query_num;

    cin >> query_num;
    rep(i, 1, query_num)
    {
        string a, b, c, d;
        cin >> a >> b >> c >> d;

        if (yydz.judge(a, b, c, d))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}