#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#define maxn 10000000
using namespace std;

int map[10][10] = {0};
// int x[10000],y[100000];
int last[maxn];     // last[i]表示操作i的上一个操作的标号
int steps[maxn][2]; // 操作i的+1位置。
struct node
{
    int map[8][8];
    int x, y, n;
    int num;
};
queue<node> a;
node q, p;

bool isCleared(node x)
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (x.map[i][j] != 0)
                return 0;
        }
    }
    return 1;
}
void output(node x)
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            printf("%d ", x.map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void boom(int x, int y)
{
    // cout<<x<<y<<endl;
    p.map[x][y] = 0;
    int lx, ly;
    lx = x;
    ly = y;
    lx = x - 1;
    while (1)
    {
        lx++;
        if (lx > 6)
            break;
        if (p.map[lx][ly] != 0)
        {
            p.map[lx][ly]++;
            // cout<<p.map[lx][ly]<<endl;
            if (p.map[lx][ly] == 5)
            {
                boom(lx, ly);
            }
            break;
        }
    }
    lx = x + 1;
    while (1)
    {
        lx--;
        if (lx < 1)
            break;
        if (p.map[lx][ly] != 0)
        {
            p.map[lx][ly]++;
            if (p.map[lx][ly] == 5)
            {
                // cout<<"("<<lx<<","<<ly<<")"<<endl;
                boom(lx, ly);
            }
            break;
        }
    }
    lx = x;
    ly = y - 1;
    while (1)
    {
        ly++;
        if (ly > 6)
            break;
        if (p.map[lx][ly] != 0)
        {
            p.map[lx][ly]++;
            if (p.map[lx][ly] == 5)
            {
                boom(lx, ly);
            }
            break;
        }
    }
    ly = y + 1;
    while (1)
    {
        ly--;
        if (ly < 1)
            break;
        if (p.map[lx][ly] != 0)
        {
            p.map[lx][ly]++;
            if (p.map[lx][ly] == 5)
            {
                boom(lx, ly);
            }
            break;
        }
    }
}

void add(int x, int y) // p在点（x，y）加一个
{
    p.map[x][y]++;
    p.n++;
    if (p.map[x][y] == 5)
    {
        boom(x, y);
    }
}

void findway(int t)
{
    while (t != 0)
    {
        cout << steps[t][0] << " " << steps[t][1] << endl;
        t = last[t];
    }
}

int main()
{
    // ceshi();
    while (true)
    {
        int remain = 0;
        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 6; j++)
            {
                cin >> map[i][j];
                if (map[i][j] != 0)
                    remain++;
            }
        }

        // 清空队列
        queue<node> empty;
        swap(a, empty);

        // 初始化起点
        node start;
        memcpy(start.map, map, sizeof map);
        start.n = 0;   // 已做操作数
        start.num = 0; // 节点编号
        a.push(start);

        // 重置操作记录
        int opCnt = 1; // 下一个操作的编号
        last[0] = -1;  // 0 号没有前驱

        bool found = false;

        for (int i = 1; i <= 6; i++)
        {
            for (int j = 1; j <= 6; j++)
            {
                q.map[i][j] = map[i][j];
            }
        }
        q.num = 0;
        q.n = 0;
        a.push(q);

        while (!a.empty() && !found)
        {
            node cur = a.front();
            a.pop();

            cout << "Hello" << endl;

            // 只要还没清完所有格子，就尝试每个非零点加一
            for (int x = 1; x <= 6 && !found; x++)
            {
                for (int y = 1; y <= 6 && !found; y++)
                {
                    if (cur.map[x][y] == 0)
                        continue;

                    p = cur;   // 复制上一次状态到 p
                    add(x, y); // 在 (x,y) 上 +1

                    p.num = opCnt;   // 给这个新状态编号
                    p.n = cur.n + 1; // 操作步数 +1

                    last[opCnt] = cur.num;
                    steps[opCnt][0] = x;
                    steps[opCnt][1] = y;
                    opCnt++;

                    if (isCleared(p))
                    {
                        // 找到解
                        cout << p.n << "\n";
                        int t = p.num;
                        // 倒着输出路径
                        vector<pair<int, int>> path;
                        while (t > 0)
                        {
                            path.emplace_back(steps[t][0], steps[t][1]);
                            t = last[t];
                        }
                        reverse(path.begin(), path.end());

                        for (const auto &pr : path)
                        {
                            int xx = pr.first;
                            int yy = pr.second;
                            cout << xx << " " << yy << "\n";
                        }
                        found = true;
                    }
                    else
                    {
                        a.push(p);
                    }
                }
            }
        }
        // 如果没找到解，可以输出 “-1” 或者其他信息
        if (!found)
        {
            cout << "No solution\n";
        }
        // 然后回到 while(true) 读取下一个关卡
    }
    return 0;
}