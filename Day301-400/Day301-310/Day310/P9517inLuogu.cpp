/*****************************************************************
 * 题目：drink
 * 描述：在区间中找到最小包含所有元素的子区间。
 * 思路：首尾遍历。
 * 对象：FindAllElement模拟寻找所有元素。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆循环

class FindAllElement
{
private:
    vector<bitset<1>> Arr;

public:
    /* 初始化，输入一个数组。 */
    FindAllElement(vector<bitset<1>> arr) : Arr(arr)
    {
    }

    /* 寻找子区间。 */
    vector<bitset<1>> find_sub_interval()
    {
        int begin = -1;
        int end = -1;
        int arrsize = Arr.size();

        rep(i, 0, arrsize - 1)
        {
            if (Arr[i].to_ulong() == 1)
            {
                begin = i;
                break;
            }
        }

        if (begin == -1)
        {
            return vector<bitset<1>>(0);
        }

        per(i, arrsize - 1, 0)
        {
            if (Arr[i].to_ulong() == 1)
            {
                end = i;
                break;
            }
        }

        return vector<bitset<1>>(Arr.begin() + begin, Arr.begin() + end + 1);
    }
};

int main()
{
    int arrsize;
    cin >> arrsize;

    vector<bitset<1>> arr(arrsize);
    rep(i, 0, arrsize - 1)
    {
        cin >> arr[i];
    }

    FindAllElement fae(arr);
    cout << fae.find_sub_interval().size() << endl;
    return 0;
}