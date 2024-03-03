/***********************************************
 * 题目：【深基3.例5】洛谷团队系统
 * 描述：输入要上传的题目，比较是本地快还是洛谷快。
 * 思路：数学计算，见Solve.svg。
 * 函数：LocalorLuogu判断本地快还是洛谷快。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

string LocalorLuogu(int Num)
{
    if (Num <= 5)
    {
        return "Local";
    }
    else
    {
        return "Luogu";
    }
}

int main()
{
    int num;
    cin >> num;

    cout << LocalorLuogu(num) << endl;
    return 0;
}