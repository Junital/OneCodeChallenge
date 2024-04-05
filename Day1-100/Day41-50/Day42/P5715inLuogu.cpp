/***********************************************
 * 题目：【深基3.例8】三位数排序
 * 描述：输入三个数，输出三个数从小到大排序。
 * 思路：sort.
 * 函数：Sort用于排序。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

/* 输入三元组，输出排序后的三元组 */
void Sort(vector<int> arr)
{
    sort(arr.begin(), arr.end());

    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
    int a, b, c;
    vector<int> Arr;
    cin >> a >> b >> c;

    Arr.push_back(a);
    Arr.push_back(b);
    Arr.push_back(c);

    Sort(Arr);
    return 0;
}