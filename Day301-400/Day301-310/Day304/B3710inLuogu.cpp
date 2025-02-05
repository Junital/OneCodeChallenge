/*****************************************************************
 * 题目：[语言月赛202302] 破碎的历史
 * 描述：给定最后的保底概率，得出可行的方案数。
 * 思路：枚举。
 * 对象：GMDebugger模拟保底调试器。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ld long double                            // 定义高精度浮点数

class GMDebugger
{
private:
public:
    /* 给定概率，保底轮数和精度，给出方案。 */
    vector<vector<ld>> debug(ld Proba, int Precision = 100)
    {
        vector<vector<ld>> Res;
        int plex = Proba * 100000000;

        rep(i, 0, Precision)
        {
            rep(j, 0, Precision)
            {
                rep(k, 0, Precision)
                {
                    rep(l, 0, Precision)
                    {
                        if (i * j * k * l == plex)
                        {
                            vector<ld> arr = {(i / (ld)Precision),
                                              (j / (ld)Precision),
                                              (k / (ld)Precision),
                                              (l / (ld)Precision)};
                            Res.push_back(arr);
                        }
                    }
                }
            }
        }

        return Res;
    }
};

int main()
{
    GMDebugger gmd;
    ld prob;

    cin >> prob;
    // cout << prob << endl;
    cout << gmd.debug(prob).size() << endl;

    return 0;
}
