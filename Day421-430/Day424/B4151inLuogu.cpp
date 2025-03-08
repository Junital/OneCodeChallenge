/*****************************************************************
 * 题目：[厦门小学生 C++ 2022] 成绩分化
 * 描述：计算最好分数和最差分数的差值。
 * 思路：活用std。
 * 空间：Tools模拟便携式工具。
 * 注意：注意数据类型。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

int main()
{
    int size;
    cin >> size;

    vector<int> arr(size);
    rep(i, 0, size - 1)
    {
        cin >> arr[i];
    }

    cout << *max_element(arr.begin(), arr.end()) -
                *min_element(arr.begin(), arr.end())
         << endl;
    return 0;
}