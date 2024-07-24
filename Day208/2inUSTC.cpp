/***************************************************************
 * 题目：Remove One Element to Make the Array Strictly Increasing
 * 描述：判断一个数组是否是只删掉一个元素就为严格增长的数组。
 * 思路：简单遍历。
 * 对象：Del1Arr模拟这种数组。
 * 注意事项：注意计算复杂度。
 *************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Del1Arr
{
private:
    /* 给出数组需要删掉的索引，判断是否是严格的。 */
    bool del_and_judge(vector<int> Arr, int idx)
    {
        int arr_size = Arr.size();
        // cout << !idx << endl;
        int last_element = Arr[!idx]; // 表示数组中未被删的上一个元素

        rep(i, (!idx) + 1, arr_size - 1)
        {
            if (i != idx)
            {
                if (Arr[i] <= last_element)
                {
                    return false;
                }
                last_element = Arr[i]; // 更新上一个元素
            }
        }

        return true;
    }

public:
    /* 思路：每次删掉其中一个，判断是否连续增长。 */
    bool judge(vector<int> Arr)
    {
        int arr_size = Arr.size();

        rep(i, 0, arr_size - 1)
        {
            if (del_and_judge(Arr, i))
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    int num;
    cin >> num;
    vector<int> arr(num);
    Del1Arr d1a;

    rep(i, 0, num - 1)
    {
        cin >> arr[i];
    }

    if (d1a.judge(arr))
    {
        cout << "T" << endl;
    }
    else
    {
        cout << "F" << endl;
    }
    return 0;
}
