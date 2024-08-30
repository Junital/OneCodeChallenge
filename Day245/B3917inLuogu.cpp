/*****************************************************************
 * 题目：[语言月赛 202401] 小跳蛙
 * 描述：每次一只小跳蛙会跳到空位，问一段时间后的状态。
 * 思路：规律就是每一位+1。
 * 对象：JumpFrog模拟小跳蛙。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class JumpFrog
{
private:
public:
    /* 输入一个小跳蛙数组，输出一段时间后的情况。 */
    vector<int> run(vector<int> arr)
    {
        int arr_size = arr.size();
        vector<int> Ans(arr_size);

        rep(i, 0, arr_size - 1)
        {
            if (arr[i] != arr_size - 1)
            {
                Ans[i] = arr[i] + 1;
            }
            else
            {
                Ans[i] = 0;
            }
        }
        return Ans;
    }
};

int main()
{
    int N;
    JumpFrog jf;

    cin >> N;
    vector<int> arr(N);

    rep(i, 0, N - 1)
    {
        cin >> arr[i];
    }

    vector<int> ans = jf.run(arr);
    for (auto e : ans)
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
