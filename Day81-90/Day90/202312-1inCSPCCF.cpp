/***********************************************
 * 题目：仓库规划
 * 描述：计算每个仓库的上级仓库。
 * 思路：m * n搜索比较。
 * 对象：CangKu模拟仓库。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class CangKu
{
private:
    vector<vector<int>> IDs;
    int Num, IDim; // 仓库数量和编码维度

public:
    /* 输入仓库数量和编码的维度 */
    CangKu(int num, int idim) : Num(num), IDim(idim)
    {
        IDs.resize(Num + 1);

        rep(i, 1, Num)
        {
            IDs[i].resize(IDim + 1);
            rep(j, 1, IDim)
            {
                cin >> IDs[i][j];
            }
        }
    }

    /* 输出每个编号对应的上级仓库。 */
    vector<int> FindFather()
    {
        vector<int> Fathers(Num + 1);

        rep(i, 1, Num)
        {
            rep(j, 1, Num)
            {
                if (j == i)
                {
                    continue;
                }

                bool Satisfy = true;
                rep(k, 1, IDim)
                {
                    if (IDs[j][k] <= IDs[i][k])
                    {
                        Satisfy = false;
                        break;
                    }
                }

                if (Satisfy)
                {
                    Fathers[i] = j;
                    break;
                }
            }
        }

        return Fathers;
    }
};

int main()
{
    int Num, IDim;
    cin >> Num >> IDim;

    CangKu ck(Num, IDim);

    vector<int> Fathers = ck.FindFather();

    rep(i, 1, Num)
    {
        cout << Fathers[i] << endl;
    }
    return 0;
}