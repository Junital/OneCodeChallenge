/*****************************************************************
 * 题目：[语言月赛 202307] 团伙首领
 * 描述：问一个数组有几个不同的元素。
 * 思路：转集合。
 * 对象：vector2set模拟数组转集合。
 * 注意：注意时间复杂度。
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

template <typename Type>
set<Type> vector2set(vector<Type> Arr)
{
    set<Type> Res(Arr.begin(), Arr.end());
    return Res;
}

int main()
{
    int size;
    cin >> size;
    vector<int> arr(size);

    rep(i, 0, size - 1)
    {
        cin >> arr[i];
    }
    cout << vector2set(arr).size() << endl;
    return 0;
}