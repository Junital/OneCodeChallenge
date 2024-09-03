/*****************************************************************
 * 题目：[语言月赛 202402] 射箭
 * 描述：某个人的分数大于其他两个人，那么出现一次事件。
 * 思路：按照金额从大到小进行判断。
 * 函数：judgeTriple判断分数是否构成神秘事件。
 * 注意：注意保持可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

bool judgeTriple(int a, int b, int c)
{
    return !(abs(b - c) <= a && a <= b + c);
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int res = judgeTriple(a, b, c);
    cout << res << endl;
    return 0;
}