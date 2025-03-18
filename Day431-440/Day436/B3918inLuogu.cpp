/*****************************************************************
 * 题目：[语言月赛 202401] 图像变换
 * 描述：将图像放大k倍。
 * 思路：将所有图像相关的内容进行封装。
 * 空间：ImgProc模拟图像处理包。
 * 注意：注意维护可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除

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
};

using namespace Tools;

namespace ImgProc
{
    using namespace Tools; // 工具包的调用

    /* 这是一个放大镜，可以放大图像 */
    class ImgScaler
    {
    private:
        int rowSca;               // 纵向的拉伸幅度
        int colSca;               // 横向的拉伸幅度
        int ImgRow;               // 原始影像的行
        int ImgCol;               // 原始影像的列
        vector<string> OriginImg; // 初始的影像

    public:
        /* 初始化，输入纵向、横向的拉伸幅度 */
        ImgScaler(int rm, int cm) : rowSca(rm), colSca(cm) {}

        /* 用于输入原始影像，参数为影像的行和列 */
        void input_img(int row, int col)
        {
            /* 初始影像清空，对行列进行赋值 */
            OriginImg.clear();
            ImgRow = row;
            ImgCol = col;

            /* 输入每一行 */
            rep(i, 1, ImgRow)
            {
                string str;
                cin >> str;

                assert(str.size() == ImgCol); // 检验一下列数对不对的上

                OriginImg.push_back(str);
            }
        }

        /* 用于输出放大后的影像 */
        void scale()
        {
            rep(i, 0, ImgRow - 1)
            {
                rep(ii, 1, rowSca) // 每一行重复rowMag次
                {
                    rep(j, 0, ImgCol - 1)
                    {
                        rep(jj, 1, colSca) // 每一列重复colMag次
                        {
                            cout << OriginImg[i][j];
                        }
                    }
                    cout << endl;
                }
            }
        }
    };

    /* 模糊处理图像，对周围四个点取平均。 */
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

    /* 对图像进行旋转。 */
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
};

using namespace ImgProc;

int main()
{
    int row, col, scale;

    cin >> row >> col >> scale;

    ImgScaler is(scale, scale);
    is.input_img(row, col);

    is.scale();
    return 0;
}