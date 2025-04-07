/*****************************************************************
 * 题目：[语言月赛202212] 洛谷三角洲
 * 描述：给出三个城市之间的距离，问城市之间的最短距离。
 * 思路：直接取最小值吧。
 * 对象：PolyMinDistance模拟多模型最短距离。
 * 注意：如果是多边形，可以用多边形的最短路径算法。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

class PolyMinDistance
{
private:
    int Poly;                  // 多边形的点数，即边数
    vector<vector<int>> Edges; // 多边形的边

    int next_point(int i) // 获取下一个点
    {
        return (i + 1) % Poly; // 下一个点
    }

    int &get_edge(int i, int j) // 获取边
    {
        if (j > i)
        {
            swap(i, j); // 交换i和j
        }
        return Edges[i][j]; // 获取边
    }

    void floyd() // Floyd算法
    {
        for (int k = 0; k < Poly; k++)
        {
            for (int i = 0; i < Poly; i++)
            {
                for (int j = 0; j < Poly; j++)
                {
                    get_edge(i, j) = min(int64_t(get_edge(i, j)),
                                         (int64_t(get_edge(i, k)) + get_edge(k, j))); // 更新最短路径
                }
            }
        }
    }

public:
    PolyMinDistance(int poly) : Poly(poly)
    {
        Edges.resize(poly, vector<int>(poly, INT_MAX)); // 初始化多边形的边
        for (int i = 0; i < Poly; i++)
        {
            cin >> get_edge(i, next_point(i)); // 输入多边形的边
            Edges[i][i] = 0;                   // 初始化多边形的边
        }
        floyd(); // 计算多边形的最短路径
    }

    // 计算多边形的最短距离
    void MinDistance(vector<int> &dis)
    {
        for (int i = 0; i < Poly; i++)
        {
            dis[i] = get_edge(i, next_point(i)); // 更新最短路径
        }
    }
};

int main()
{
    const int N = 3;         // 多边形的点数
    PolyMinDistance poly(N); // 初始化多边形
    vector<int> dis(N);      // 存储多边形的最短路径
    poly.MinDistance(dis);   // 计算多边形的最短路径

    for (auto d : dis)
    {
        cout << d << endl; // 输出多边形的最短路径
    }
    return 0;
}