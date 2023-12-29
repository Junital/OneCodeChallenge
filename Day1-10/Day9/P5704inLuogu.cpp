/************************************************************
 * 题目：【深基2.例6】字母转换
 * 要求：输入一个小写字母，输出一个大写字母
 * 作者：Junital
 * 思路：ASCII码进行查询一下即可发现规律。
 * 函数：LowercaseToCapital小写字母转大写字母
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

/* 输入一个小写字母，通过ASCII码减去固定值得到大写字母 */
char LowercaseToCapital(char lowercase)
{
    char capital = '?'; // 对应的大写字母，防止其他情况先初始化为‘？’
    if (lowercase >= 'a' && lowercase <= 'z')
    {
        capital = lowercase - ('a' - 'A'); // 不知道小写字母和大写字母的距离，直接这样表示吧
    }

    return capital;
}

int main()
{
    // cout << (int)'a' << " " << (int)'A' << endl;
    char lowercase;
    cin >> lowercase;
    char capital = LowercaseToCapital(lowercase); // 得到大写字母
    cout << capital << endl;
    return 0;
}