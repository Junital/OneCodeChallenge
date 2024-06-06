/**********************************************************
 * 题目：基因相关性
 * 描述：输入两个字符串，输出字符串相似程度。
 * 思路：遍历一次。
 * 函数：string_similarity用于匹配字符串。
 * 注意：保证封装良好。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

double string_similarity(string A, string B)
{
    assert(A.length() == B.length());
    int Len = A.length(); // 字符串长度
    int SameCh = 0;       // 相同字符的个数
    rep(i, 0, Len - 1)
    {
        if (A[i] == B[i])
        {
            SameCh++;
        }
    }

    return SameCh * 1.0 / Len;
}

int main()
{
    double threshold;
    string DNA_1, DNA_2;

    cin >> threshold;
    cin >> DNA_1 >> DNA_2;

    double similarity = string_similarity(DNA_1, DNA_2);
    if (similarity >= threshold)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}