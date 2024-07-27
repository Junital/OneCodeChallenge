/*********************************************************
 * 题目：[语言月赛202305] 超链接
 * 描述：一个图谱结构，然后访问两次，将集合合并。
 * 思路：自行构造图谱。
 * 变量：DirectedGraph模拟有向图。
 * 注意：注意时间复杂度。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

template <typename Container>
Container Union(const Container &A, const Container &B)
{
    Container result;
    set_union(A.begin(), A.end(), B.begin(), B.end(),
              inserter(result, result.begin()));
    return result;
}

template <typename Type>
set<Type> vector2set(vector<Type> Arr)
{
    set<Type> Res(Arr.begin(), Arr.end());
    return Res;
}

int main()
{
    map<int, vector<int>> Neighbors; // 邻接关系
    int vertice_num;
    set<int> ans = {1};
    const int link_time = 2; // 点击次数

    cin >> vertice_num;
    rep(i, 1, vertice_num)
    {
        int link_num;
        cin >> link_num;
        Neighbors[i].resize(link_num);

        rep(j, 0, link_num - 1)
        {
            cin >> Neighbors[i][j];
        }
    }

    rep(i, 1, link_time)
    {
        set<int> tmp = ans;
        for (auto x : tmp)
        {
            ans = Union(ans, vector2set(Neighbors[x]));
        }
    }

    cout << ans.size() << endl;
    return 0;
}
