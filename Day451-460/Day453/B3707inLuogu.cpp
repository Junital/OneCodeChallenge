/*****************************************************************
 * 题目：[语言月赛202302] 风神瞳
 * 描述：问象棋棋子能否吃掉另一个棋子。
 * 思路：特殊判断。
 * 空间：ChineseChess模拟中国象棋包。
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

// 这里是一个模拟中国象棋的包
namespace ChineseChess
{
    /* 坐标 */
    struct Coord
    {
        int x, y;
        Coord(int x = 0, int y = 0) : x(x), y(y) {}
        bool operator==(const Coord &other) const
        {
            return x == other.x && y == other.y;
        }
    };

    /* 棋子 */
    class Piece
    {
    protected:
        Coord pos; // 棋子坐标
    public:
        Piece(int x = 0, int y = 0) : pos(x, y) {}             // 构造函数
        Piece(const Coord &coord) : pos(coord) {}              // 构造函数
        virtual bool eat_judge(const Coord &target) const = 0; // 吃子判断
    };

    /* 车 */
    class Rook : public Piece
    {
    public:
        Rook(int x = 0, int y = 0) : Piece(x, y) {} // 构造函数
        Rook(const Coord &coord) : Piece(coord) {}  // 构造函数
        bool eat_judge(const Coord &target) const override
        {
            return (pos.x == target.x || pos.y == target.y);
        }
    };

    /* 炮 */
    class Cannon : public Piece
    {
    public:
        Cannon(int x = 0, int y = 0) : Piece(x, y) {} // 构造函数
        Cannon(const Coord &coord) : Piece(coord) {}  // 构造函数
        bool eat_judge(const Coord &target) const override
        {
            return false; // 因为目前就支持两个子，所以炮的吃子判断不需要实现
        }
    };

    /* 马 */
    class Horse : public Piece
    {
    public:
        Horse(int x = 0, int y = 0) : Piece(x, y) {} // 构造函数
        Horse(const Coord &coord) : Piece(coord) {}  // 构造函数
        bool eat_judge(const Coord &target) const override
        {
            return (abs(pos.x - target.x) == 2 && abs(pos.y - target.y) == 1) ||
                   (abs(pos.x - target.x) == 1 && abs(pos.y - target.y) == 2);
        }
    };

    /* 象 */
    class Elephant : public Piece
    {
    public:
        Elephant(int x = 0, int y = 0) : Piece(x, y) {} // 构造函数
        Elephant(const Coord &coord) : Piece(coord) {}  // 构造函数
        bool eat_judge(const Coord &target) const override
        {
            return (abs(pos.x - target.x) == 2 && abs(pos.y - target.y) == 2);
        }
    };
};

using namespace ChineseChess;

int main()
{
    int type;
    cin >> type;                  // 输入棋子类型
    class Piece *piece = nullptr; // 棋子指针

    Coord begin, end;          // 棋子坐标
    cin >> begin.x >> begin.y; // 输入棋子坐标
    cin >> end.x >> end.y;     // 输入目标坐标

    if (type == 1)
    {
        piece = new Rook(begin); // 车
    }
    else if (type == 2)
    {
        piece = new Cannon(begin); // 炮
    }
    else if (type == 3)
    {
        piece = new Horse(begin); // 马
    }
    else if (type == 4)
    {
        piece = new Elephant(begin); // 象
    }
    else
    {
        throw invalid_argument("Invalid piece type");
    }

    // 判断是否能吃掉
    if (piece->eat_judge(end))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}