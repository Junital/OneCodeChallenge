/************************************************************
 * 题目：轰炸III
 * 要求：每次会轰炸一个区域，对于我们关心的几个点，需要给出是否被轰炸，如果轰炸了还需要输出被炸了几次以及最后一次是第几轮。
 * 作者：Junital
 * 函数Boom来模拟爆炸，函数Query来模拟查询
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

int BoomMap[105][105][2] = {0}; // 表示轰炸的地图，第一层(Map[x][y][0])是被轰炸的次数，第二层(Map[x][y][1])是最新轰炸的轮数
int n, m;                       // n代表地图的长度，m代表宽度

/* 用于模拟爆炸，参数分别为（左上角x坐标，左上角y坐标，右下角x坐标，右下角y坐标，爆炸轮次） */
void Boom(int ulx, int uly, int drx, int dry, int turn)
{
    for (int i = ulx; i <= drx; i++)
    {
        for (int j = uly; j <= dry; j++)
        {
            BoomMap[i][j][0]++;
            BoomMap[i][j][1] = turn;
        }
    }
}

/* 用于对关心点进行查询，输入分别是x坐标和y坐标 */
void Query(int x, int y)
{
    if (BoomMap[x][y][0] == 0) // 如果爆炸次数为零，那么是安全的
    {
        cout << "N" << endl;
    }
    else
    {
        // 这里就是爆炸过了
        cout << "Y " << BoomMap[x][y][0] << " " << BoomMap[x][y][1] << endl;
    }
}

int main()
{
    int boom_cnt;  // 表示轰炸的次数
    int query_cnt; // 表示查询点的个数

    cin >> n >> m >> boom_cnt >> query_cnt;

    /* 开始进行爆炸*/
    for (int i = 1; i <= boom_cnt; i++)
    {
        int ulx, uly, drx, dry;
        cin >> ulx >> uly >> drx >> dry;
        Boom(ulx, uly, drx, dry, i);
    }

    /* 开始进行查询 */
    for (int i = 1; i <= query_cnt; i++)
    {
        int x, y;
        cin >> x >> y;
        Query(x, y);
    }

    return 0;
}