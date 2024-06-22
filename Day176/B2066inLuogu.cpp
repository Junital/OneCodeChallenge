/**********************************************************
 * 题目：救援
 * 描述：计算救援所花的时间。
 * 思路：普通计算，遍历即可。
 * 对象：Rescure模拟救援。
 * 注意：注意取上界。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 屋顶，包括坐标和人数 */
struct Roof
{
    double X;
    double Y;
    int People;
};

/* 救援对象 */
class Rescure
{
private:
    int Roof_Num;             // 屋顶数量
    vector<Roof> Roofs;       // 屋顶
    const int SPEED = 50;     // 速度
    const double LEAVE = 1.5; // 人的逃跑速度

public:
    /* 初始化，输入屋顶数量 */
    Rescure(int num) : Roof_Num(num)
    {
        rep(i, 1, Roof_Num)
        {
            double x, y;
            int people;
            cin >> x >> y >> people;
            Roofs.push_back({x, y, people});
        }
    }

    /* 开始救援 */
    int get_time()
    {
        double t = 0; // 时间

        for (auto r : Roofs)
        {
            double dis = sqrt(r.X * r.X + r.Y * r.Y);
            t += dis / SPEED;
            t += dis / SPEED;
            t += r.People * LEAVE;
        }

        return ceil(t);
    }
};

int main()
{
    int roof_num;
    cin >> roof_num;

    Rescure res(roof_num);

    cout << res.get_time() << endl;
    return 0;
}
