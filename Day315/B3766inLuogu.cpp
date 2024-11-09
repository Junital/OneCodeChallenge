/*****************************************************************
 * 题目：[语言月赛202305] 排排队，做游戏
 * 描述：将数组元素进行重新排布。
 * 思路：遍历操作。
 * 对象：ArrangeArr模拟数组元素重排列。
 * 注意：注意时间复杂度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ArrangeArr
{
private:
public:
    /* 输入数组和间隔，输出排列后的数组。 */
    void arrange(vector<int> &Arr, int Step)
    {
        int arrsize = Arr.size();
        vector<int> Res(arrsize);

        int idx = 0;
        rep(i, 0, Step - 1)
        {
            for (int j = i; j < arrsize; j += Step)
            {
                Res[idx] = Arr[j];
                idx++;
            }
        }

        rep(i, 0, arrsize - 1)
        {
            Arr[i] = Res[i];
        }
    }
};

int main()
{
    int arrsize, arrange_time;
    cin >> arrsize >> arrange_time;

    ArrangeArr aa;
    vector<int> Arr(arrsize);

    rep(i, 0, arrsize - 1)
    {
        cin >> Arr[i];
    }

    rep(i, 1, arrange_time)
    {
        int step;
        cin >> step;
        aa.arrange(Arr, step);
    }

    rep(i, 0, arrsize - 1)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
    return 0;
}
