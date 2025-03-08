/*****************************************************************
 * 题目：[语言月赛 202307] 署前街少年
 * 描述：数组变换。
 * 思路：预处理。
 * 对象：TriFunctionTransform模拟三角函数变换。
 * 注意：注意溢出情况。
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

class TriFunctionTransform
{
private:
public:
    TriFunctionTransform() {}

    /* 请求，输入一个数组，输出变换后的数组。 */
    vector<int> query(vector<int> arr, int mod)
    {
        map<int, ll> parts;
        int arr_len = arr.size();

        rep(i, 0, arr_len - 1)
        {
            parts[(i + 1) % mod] += arr[i];
        }
        // cout << "Hello" << endl;

        vector<int> res;

        rep(i, 0, arr_len - 1)
        {
            // cout << i << endl;
            if ((i + 1) % 2)
            {
                int part_idx = (i + 1) % mod;
                auto it = parts.find(part_idx);
                // cout << part_idx << endl;
                if (it != parts.end())
                {
                    res.push_back(it->second % (i + 1));
                }
                else
                {
                    throw invalid_argument("Unexpected.");
                }
            }
            else
            {
                res.push_back(arr[i]);
            }
        }

        return res;
    }
};

int main()
{
    int size, mod;
    TriFunctionTransform tft;
    cin >> size >> mod;

    vector<int> arr(size * 2);
    rep(i, 0, size * 2 - 1)
    {
        cin >> arr[i];
    }

    auto res = tft.query(arr, mod);
    for (auto element : res)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}