/*****************************************************************
 * 题目：最大数输出
 * 描述：输入三个数，输出最大的数。
 * 思路：应该有max_element这个函数。
 * 函数：无。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{

    int a, b, c;
    vector<int> Arr;
    cin >> a >> b >> c;

    Arr.push_back(a);
    Arr.push_back(b);
    Arr.push_back(c);

    auto res = max_element(Arr.begin(), Arr.end());
    cout << *res << endl;
    return 0;
}
