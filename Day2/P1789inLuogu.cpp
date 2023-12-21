/************************************************************
 * 题目：【Mc生存】插火把
 * 要求：火把和萤石能点亮一部分区域，没点亮的地方会生怪，需要计算生怪点的个数。
 * 作者：Junital
 * 函数：CountMonsterPoint计算生怪点，TorchLight火把点亮，FluoriteLight萤石点亮，LightPoint点亮某个特定的点。
 * 全局变量：MCMap全局的地图
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

int n; // 地图的大小（地图是正方形）

int MCMap[105][105] = {0}; // 地图，每个点Light代表有光，其余代表没光。

#define Light 1

void LightPoint(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= n)
    {
        MCMap[x][y] = Light;
    }
}

void TorchLight(int x, int y) // 思路：将火把能照亮的地方都照亮
{
    /****************
    |暗|暗| 光 |暗|暗|
    |暗|光| 光 |光|暗|
    |光|光|火把|光|光|
    |暗|光| 光 |光|暗|
    |暗|暗| 光 |暗|暗|
    ****************/
    LightPoint(x, y);
    LightPoint(x - 1, y);
    LightPoint(x - 2, y);
    LightPoint(x - 1, y - 1); // 左下
    LightPoint(x - 1, y + 1); // 左上
    LightPoint(x, y + 1);
    LightPoint(x, y + 2);
    LightPoint(x, y - 1);
    LightPoint(x, y - 2);
    LightPoint(x + 1, y);
    LightPoint(x + 2, y);
    LightPoint(x + 1, y - 1); // 右下
    LightPoint(x + 1, y + 1); // 右上
}

void FluoriteLight(int x, int y) // 思路：将萤石能照亮的地方都照亮
{
    /****************
    |光|光| 光 |光|光|
    |光|光| 光 |光|光|
    |光|光|萤石|光|光|
    |光|光| 光 |光|光|
    |光|光| 光 |光|光|
    ****************/
    LightPoint(x, y);
    LightPoint(x - 1, y);
    LightPoint(x - 2, y);
    LightPoint(x - 1, y - 1); // 左下
    LightPoint(x - 1, y + 1); // 左上

    /*下面是只有萤石才有的六个亮点*/
    LightPoint(x - 1, y + 2);
    LightPoint(x - 1, y - 2);
    LightPoint(x - 2, y + 1);
    LightPoint(x - 2, y - 1);
    LightPoint(x - 2, y + 2);
    LightPoint(x - 2, y - 2);

    LightPoint(x, y + 1);
    LightPoint(x, y + 2);
    LightPoint(x, y - 1);
    LightPoint(x, y - 2);
    LightPoint(x + 1, y);
    LightPoint(x + 2, y);

    LightPoint(x + 1, y - 1); // 右下
    LightPoint(x + 1, y + 1); // 右上

    /*下面是只有萤石才有的六个亮点*/
    LightPoint(x + 1, y + 2);
    LightPoint(x + 1, y - 2);
    LightPoint(x + 2, y + 1);
    LightPoint(x + 2, y - 1);
    LightPoint(x + 2, y + 2);
    LightPoint(x + 2, y - 2);
}

int CountMonsterPoint()
{
    // 统计地图内的没光的区域
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (MCMap[i][j] != Light)
            {
                sum++;
            }
        }
    }
    return sum;
}

int main()
{
    int torch_cnt;    // 火把的数量
    int fluorite_cnt; // 萤石的数量
    cin >> n >> torch_cnt >> fluorite_cnt;

    for (int i = 1; i <= torch_cnt; i++)
    {
        int x, y;
        cin >> x >> y;
        TorchLight(x, y);
    }

    for (int i = 1; i <= fluorite_cnt; i++)
    {
        int x, y;
        cin >> x >> y;
        FluoriteLight(x, y);
    }

    cout << CountMonsterPoint() << endl;
    return 0;
}
