/*****************************************************************
 * 题目：[GESP样题 三级] 逛商场
 * 描述：需要多少才能保持在阈值之下。
 * 思路：简单加法。
 * 函数：arr_subsum模拟局部求和。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

int arr_subsum(vector<int> Arr, int Threshold)
{
    int arrsize = Arr.size();
    int cnt = 0;
    rep(i, 0, arrsize - 1)
    {
        if (Threshold >= Arr[i])
        {
            Threshold -= Arr[i];
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int arrsize;
    cin >> arrsize;

    vector<int> arr(arrsize);

    rep(i, 0, arrsize - 1)
    {
        cin >> arr[i];
    }

    int threshold;
    cin >> threshold;

    cout << arr_subsum(arr, threshold) << endl;
    return 0;
}
