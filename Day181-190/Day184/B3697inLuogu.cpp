/***********************************************
 * 题目：[语言月赛202301] 铺地毯
 * 描述：给定房间的大小，问如果不裁剪，能否铺满地毯？
 * 思路：整除思想。
 * 对象：Room模拟房间。
 * 注意：注意数据范围。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Room
{
private:
    ll Length; // 长
    ll Width;  // 宽

public:
    /* 初始化，输入房间的长宽。 */
    Room(ll l, ll w) : Length(l), Width(w) {}

    /* 铺地毯，输入正方形地毯的大小。 */
    ll carpet(ll Size)
    {
        if (Length % Size != 0 || Width % Size != 0)
        {
            return -1;
        }

        return (Length / Size) * (Width / Size);
    }
};

int main()
{
    ll length, width; // 房间长宽
    cin >> length >> width;

    Room room(length, width);

    ll size; // 地毯大小
    cin >> size;

    cout << room.carpet(size) << endl;
    return 0;
}