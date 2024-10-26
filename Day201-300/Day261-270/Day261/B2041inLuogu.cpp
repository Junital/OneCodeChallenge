/*****************************************************************
 * 题目：收集瓶盖赢大奖
 * 描述：满足一项要求即可。
 * 思路：加一些拓展接口。
 * 函数：MultiThreshold模拟多阈值。
 * 注意：提升代码可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class MultiThreshold
{
private:
    vector<int> Thres; // 阈值数组
    bool SingleS;      // 是否满足一种即可

public:
    /* 初始化，输入一个阈值数组，并且指定要同时满足还是只要满足一种。 */
    MultiThreshold(vector<int> thres, bool single_satisfy = false)
        : Thres(thres), SingleS(single_satisfy) {}

    /* 判断是否满足条件。 */
    bool judge(vector<int> Arr)
    {
        assert(Arr.size() == Thres.size());

        int arrlen = Arr.size();

        if (SingleS)
        {
            rep(i, 0, arrlen - 1)
            {
                if (Arr[i] >= Thres[i])
                {
                    return true;
                }
            }

            return false;
        }
        else
        {
            rep(i, 0, arrlen - 1)
            {
                if (Arr[i] < Thres[i])
                {
                    return false;
                }
            }

            return true;
        }
    }
};

int main()
{
    const vector<int> thres = {10, 20};
    const int thres_size = thres.size();

    MultiThreshold mt(thres, true);
    vector<int> arr(thres_size);

    rep(i, 0, thres_size - 1)
    {
        cin >> arr[i];
    }

    cout << mt.judge(arr) << endl;
    return 0;
}
