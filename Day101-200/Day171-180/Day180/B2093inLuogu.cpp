/**********************************************************
 * 题目：查找特定的值
 * 描述：在数组中找特定元素，找不到返回-1。
 * 思路：STL find函数试试。
 * 函数：暂时无。
 * 注意：注意拓展性。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 输入数组、元素，输出元素对应的下标。
若有多个返回下标最小的那个。如果没找到返回-1。 */

template <typename Container>
int vector_find(vector<Container> Arr, Container Element)
{
    auto it = find(Arr.begin(), Arr.end(), Element);

    if (it == Arr.end())
    {
        return -1;
    }
    return it - Arr.begin();
}

int main()
{
    vector<int> Arr;
    int ArrSize;
    int element_tofind;

    cin >> ArrSize;
    Arr.resize(ArrSize);

    rep(i, 0, ArrSize - 1)
    {
        cin >> Arr[i];
    }

    cin >> element_tofind;
    cout << vector_find(Arr, element_tofind) << endl;
    return 0;
}
