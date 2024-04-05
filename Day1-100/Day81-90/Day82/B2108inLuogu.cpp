/***********************************************
 * 题目：图像模糊处理
 * 描述：对于像素点，每个点与周围四个点取平均。
 * 思路：数学计算。
 * 函数：ImageBlur对图像进行模糊处理。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 四舍五入 */
int Approximate(double Num)
{
    double Ceil = ceil(Num);
    double Floor = floor(Num);

    if (Ceil - Num <= Num - Floor)
    {
        return (int)Ceil;
    }
    else
    {
        return (int)Floor;
    }
}

vector<vector<int>> ImageBlur(vector<vector<int>> Img)
{
    int Row = Img.size();
    int Col = Img[0].size();

    vector<vector<int>> BlurImg;
    BlurImg.resize(Row);

    rep(i, 0, Row - 1)
    {
        BlurImg[i].resize(Col);
        rep(j, 0, Col - 1)
        {
            if (i == 0 || i == Row - 1 || j == 0 || j == Col - 1)
            {
                BlurImg[i][j] = Img[i][j];
            }
            else
            {
                BlurImg[i][j] = Approximate(((double)Img[i][j] + Img[i - 1][j] +
                                             Img[i + 1][j] + Img[i][j - 1] + Img[i][j + 1]) /
                                            5);
            }
        }
    }

    return BlurImg;
}

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<int>> img;
    img.resize(row);

    rep(i, 0, row - 1)
    {
        img[i].resize(col);
        rep(j, 0, col - 1)
        {
            cin >> img[i][j];
        }
    }

    vector<vector<int>> blurimg = ImageBlur(img);

    for (auto R : blurimg)
    {
        for (auto C : R)
        {
            cout << C << " ";
        }
        cout << endl;
    }

    return 0;
}
