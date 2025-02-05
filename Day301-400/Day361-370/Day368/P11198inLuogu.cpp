/*****************************************************************
 * 题目：[JOIG 2024] 三連続 / Three Consecutive
 * 描述：问一个字符串是否存在ooo。
 * 思路：查找。
 * 对象：无。
 * 注意：注意通用性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    const string target = "ooo";

    int size;
    string str;
    cin >> size >> str;

    int res = str.find(target);
    if (res >= 0 && res < size)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}