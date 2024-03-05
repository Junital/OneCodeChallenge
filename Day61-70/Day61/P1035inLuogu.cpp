/***********************************************
 * 题目：[NOIP2002 普及组] 级数求和
 * 描述：S_n = 1 + \frac{1}{2} + \frac{1}{3} + \dots + \frac{1}{n}
        给出一个正整数，求出最小的n，刚好S_n > 这个正整数。
 * 思路：模拟求和。
 * 函数：FindMiniGrade用来寻找最小的级数。
 * 注意：时间限制，不要超时。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 输入正整数，返回最小大于这个正整数级数的序号。 */
int FindMiniGrade(int Threshold)
{
    double GradeNum = 0; // 计算目前的级数
    int i = 0;           // 记录级数的序号

    while (1)
    {
        if (GradeNum > (double)Threshold) // 通过验证，k=15时没超时
        {
            break;
        }
        i++;
        GradeNum += (1.0 / i);
    }

    return i;
}

int main()
{
    int threshold;

    cin >> threshold;

    cout << FindMiniGrade(threshold) << endl;

    return 0;
}