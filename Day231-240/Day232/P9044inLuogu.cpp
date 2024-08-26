/*****************************************************************
 * 题目：[PA2021] Koszulki
 * 描述：排序，选出至少k个人，同时如果有人与第k个分数相同，也选入。
 * 思路：利用二分查找。
 * 函数：get_baseline获取通过人数。
 * 注意：注意拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

int get_baseline(vector<int> Arr, int Lower)
{
    sort(Arr.begin(), Arr.end());

    int ArrSize = Arr.size();
    int MinScore = Arr[ArrSize - Lower];
    return Arr.end() - lower_bound(Arr.begin(), Arr.end(), MinScore);
}

int main()
{
    int size, lower;
    cin >> size >> lower;

    vector<int> arr(size);

    rep(i, 0, size - 1)
    {
        cin >> arr[i];
    }
    cout << get_baseline(arr, lower) << endl;
    return 0;
}