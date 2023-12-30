/************************************************************
 * 题目：Crying 与爬山
 * 要求：给一个数组，输出极值点的个数(f(x - 1) > f(x) < f(x + 1))
 * 作者：Junital
 * 思路：直接O(1)遍历
 * 函数：FindValleys寻找极值点个数
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 简便循环

/* 输入一个数组，返回这个数组里面有多少个极值点 */
int FindValleys(vector<int> arr)
{
    int size = arr.size(); // 计算数组大小
    int valley_cnt = 0;    // 计算极值点数量

    /* 计算出比左边小，比右边也小的点 */
    rep(i, 1, size - 2)
    {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
        {
            valley_cnt++;
        }
    }

    return valley_cnt;
}

int main()
{
    int n;           // 数组的大小
    vector<int> arr; // 数组

    cin >> n;
    rep(i, 1, n)
    {
        int x; // 暂时存放数组元素
        cin >> x;
        arr.push_back(x);
    }

    cout << FindValleys(arr) << endl;
    return 0;
}