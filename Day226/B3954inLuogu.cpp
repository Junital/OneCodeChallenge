/*****************************************************************
 * 题目：[GESP202403 二级] 乘法问题
 * 描述：累乘操作。
 * 思路：将累乘进行封装。
 * 函数：MultiTimes模拟累乘。
 * 注意：注意判断结果的范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++)

class MultiTimes
{
private:
    int Threshold;

public:
    /* 初始化，输入阈值。 */
    MultiTimes(int thres = 1000000) : Threshold(thres) {}

    /* 累乘。 */
    int calculate(vector<int> Arr)
    {
        int Res = 1;
        for (auto element : Arr)
        {
            Res *= element;
            if (Res > Threshold)
            {
                return -1;
            }
        }
        return Res;
    }
};

int main()
{
    const int thres = 1e6;
    MultiTimes m(thres);
    int arrsize;
    cin >> arrsize;

    vector<int> arr(arrsize);
    rep(i, 0, arrsize - 1)
    {
        cin >> arr[i];
    }

    int res = m.calculate(arr);
    if (res == -1)
    {
        cout << ">" << thres << endl;
    }
    else
    {
        cout << res << endl;
    }
    return 0;
}
