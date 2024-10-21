/*****************************************************************
 * 题目：[语言月赛202209] 课程QQ群
 * 描述：给定一个数组，问有多少个和目标相同的元素。
 * 思路：用一个map进行模拟。
 * 对象：ArrayCount模拟数组统计。
 * 注意：降低空间复杂度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

template <typename T>
class ArrayCount
{
private:
    vector<T> Arr;
    map<T, int> ElementCount;

    void init()
    {
        for (auto e : Arr)
        {
            ElementCount[e]++;
        }
    }

public:
    /* 初始化，输入一个数组 */
    ArrayCount(vector<T> arr) : Arr(arr)
    {
        init();
    }

    /* 请求某个元素的出现的次数。 */
    int query(T element)
    {
        return ElementCount[element];
    }
};

int main()
{
    int element_num, query;

    cin >> element_num >> query;

    vector<int> arr(element_num);
    rep(i, 0, element_num - 1)
    {
        cin >> arr[i];
    }

    ArrayCount<int> ac(arr);

    cout << ac.query(query) << endl;
    return 0;
}