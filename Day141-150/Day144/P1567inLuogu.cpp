/******************************************************
 * 题目：统计天数
 * 描述：统计连续上升最大长度。
 * 思路：遍历一遍即可。
 * 对象：ContinualUP模拟连续上升。
 * 注意：数字大小。
 ******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ContinualUP
{
private:
public:
    /* 初始化，输入数组，返回连续上升最大长度。 */
    int ContinuUPLen(vector<int> Arr)
    {
        int MaxLen = 0;           // 最长长度
        int CurrentLen = 1;       // 目前长度
        int ArrSize = Arr.size(); // 数组长度

        rep(i, 1, ArrSize - 1)
        {
            if (Arr[i] > Arr[i - 1])
            {
                CurrentLen++;
            }
            else
            {
                MaxLen = max(CurrentLen, MaxLen);
                CurrentLen = 1;
            }
        }

        MaxLen = max(CurrentLen, MaxLen); // 还得比较一下

        return MaxLen;
    }
};

int main()
{
    int arrsize;
    cin >> arrsize;

    vector<int> arr(arrsize);
    ContinualUP cup;

    rep(i, 0, arrsize - 1)
    {
        cin >> arr[i];
    }

    cout << cup.ContinuUPLen(arr) << endl;
    return 0;
}