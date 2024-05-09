/***************************************************************
 * 题目：图像旋转
 * 描述：输入一张图片，输出顺时针旋转90度后的图片。
 * 思路：简单输入一下，然后直接输出吧，就不拓展功能了。
 * 对象：RotateImage模拟旋转图片。
 * 注意：注意输入逻辑。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆循环

class RotateImage
{
private:
    vector<vector<int>> RotImg;
    int Row, Col;

public:
    /* 初始化，输入行列。 */
    RotateImage(int row, int col)
        : Row(row), Col(col)
    {
        RotImg.resize(Col);
        rep(i, 0, Col - 1)
        {
            RotImg[i].resize(Row);
        }

        per(j, Row - 1, 0)
        {
            rep(i, 0, Col - 1)
            {
                cin >> RotImg[i][j];
            }
        }
    }

    /* 获取旋转后的图片。 */
    vector<vector<int>> getRotImg()
    {
        return RotImg;
    }
};

int main()
{
    int row, col;

    cin >> row >> col;
    RotateImage RI(row, col);

    vector<vector<int>> Img = RI.getRotImg();

    for (auto r : Img)
    {
        for (auto i : r)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
