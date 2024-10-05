/*****************************************************************
 * 题目：与指定数字相同的数的个数
 * 描述：给出数组中某个数字出现了几次。
 * 思路：map统计。
 * 对象：ArrayCount模拟数组统计。
 * 注意：注意拓展性。
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
    int arrsize;
    cin >> arrsize;

    vector<int> arr(arrsize);
    rep(i, 0, arrsize - 1)
    {
        cin >> arr[i];
    }

    ArrayCount<int> ac(arr);

    int query;
    cin >> query;
    cout << ac.query(query);
    return 0;
}
