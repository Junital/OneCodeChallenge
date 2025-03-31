/*****************************************************************
 * 题目：「GMOI R2-T1」轴对称
 * 描述：有一张空白照片，每次修改像素颜色，问每一次修改后图片是否对称。
 * 思路：封装一个改变像素的函数和一个判断对称的函数，直接模拟。
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
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

namespace ImgProc
{
    /* 矩阵图像 */
    struct MatrixImg
    {
        int row, col;                // 行和列
        vector<vector<int>> ImgData; // 图像数据
        MatrixImg(int r, int c) : row(r), col(c)
        {
            ImgData.resize(row);
            for (int i = 0; i <= row - 1; i++)
            {
                ImgData[i].resize(col);
            }
        }
    };

    /* 字符串图像 */
    struct StringImg
    {
        int row, col;           // 行和列
        vector<string> ImgData; // 图像数据
        StringImg(int r, int c) : row(r), col(c)
        {
            ImgData.resize(row);
            for (int i = 0; i <= row - 1; i++)
            {
                ImgData[i].resize(col);
            }
        }

        void clear()
        {
            ImgData.clear();
        }

        void resize(int r, int c)
        {
            row = r;
            col = c;
            ImgData.resize(row);
        }

        void push_back(string str)
        {
            if (str.size() != col)
            {
                throw invalid_argument("String length does not match row size");
            }
            ImgData.push_back(str);
        }
    };

    struct RGB
    {
        static const int Mod = 256;                                      // RGB的最大值
        int R, G, B;                                                     // RGB值
        RGB(int r, int g, int b) : R(r % Mod), G(g % Mod), B(b % Mod) {} // 构造函数
        RGB() : R(0), G(0), B(0) {}                                      // 默认构造函数
        RGB operator+(const RGB &other) const
        {
            return RGB((int64_t(R) + other.R) % Mod,
                       (int64_t(G) + other.G) % Mod,
                       (int64_t(B) + other.B) % Mod); // 重载加法运算符
        } // 重载加法运算符

        bool operator==(const RGB &other) const
        {
            return (R == other.R && G == other.G && B == other.B);
        } // 重载等于运算符

        bool operator!=(const RGB &other) const
        {
            return (R != other.R || G != other.G || B != other.B);
        } // 重载不等于运算符

        void set_RGB(int r, int g, int b)
        {
            R = r % Mod;
            G = g % Mod;
            B = b % Mod;
        } // 设置RGB值

        void set_R(int r)
        {
            R = r % Mod;
        } // 设置R值

        void set_G(int g)
        {
            G = g % Mod;
        } // 设置G值

        void set_B(int b)
        {
            B = b % Mod;
        } // 设置B值
    };

    /* RGB图像 */
    struct RGBImg
    {
        int row, col;                // 行和列
        vector<vector<RGB>> ImgData; // 图像数据
        RGBImg(int r, int c) : row(r), col(c)
        {
            ImgData.resize(row);
            for (int i = 0; i <= row - 1; i++)
            {
                ImgData[i].resize(col, RGB()); // 初始化为黑色
            }
        }
    };

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

    /* 这是一个放大镜，可以放大图像 */
    class ImgScaler
    {
    private:
        int rowSca;          // 纵向的拉伸幅度
        int colSca;          // 横向的拉伸幅度
        int ImgRow;          // 原始影像的行
        int ImgCol;          // 原始影像的列
        StringImg OriginImg; // 初始的影像

    public:
        /* 初始化，输入纵向、横向的拉伸幅度 */
        ImgScaler(int rm, int cm) : rowSca(rm), colSca(cm), OriginImg(0, 0) {}

        /* 用于输入原始影像，参数为影像的行和列 */
        void input_img(int row, int col)
        {
            /* 初始影像清空，对行列进行赋值 */
            OriginImg.clear();
            OriginImg.resize(row, col);

            /* 输入每一行 */
            for (int i = 1; i <= ImgRow; i++)
            {
                string str;
                cin >> str;

                OriginImg.push_back(str);
            }
        }

        /* 用于输出放大后的影像 */
        void scale()
        {
            for (int i = 0; i <= ImgRow - 1; i++)
            {
                for (int ii = 1; ii <= rowSca; ii++) // 每一行重复rowMag次
                {
                    for (int j = 0; j <= ImgCol - 1; j++)
                    {
                        for (int jj = 1; jj <= colSca; jj++) // 每一列重复colMag次
                        {
                            cout << OriginImg.ImgData[i][j];
                        }
                    }
                    cout << endl;
                }
            }
        }
    };

    /* 模糊处理图像，对周围四个点取平均。 */
    MatrixImg ImageBlur(MatrixImg img)
    {
        int Row = img.row;
        int Col = img.col;

        MatrixImg BlurImg(Row, Col); // 创建一个新的图像对象

        for (int i = 0; i <= Row - 1; i++)
        {
            for (int j = 0; j <= Col - 1; j++)
            {
                if (i == 0 || i == Row - 1 || j == 0 || j == Col - 1)
                {
                    BlurImg.ImgData[i][j] = img.ImgData[i][j];
                }
                else
                {
                    BlurImg.ImgData[i][j] = Approximate(((double)img.ImgData[i][j] + img.ImgData[i - 1][j] + img.ImgData[i + 1][j] + img.ImgData[i][j - 1] + img.ImgData[i][j + 1]) / 5); // 对周围四个点取平均
                }
            }
        }

        return BlurImg;
    }

    /* 对图像进行旋转。 */
    class RotateImage
    {
    private:
        MatrixImg RotImg; // 图像

    public:
        /* 初始化，输入行列。 */
        RotateImage(int row, int col)
            : RotImg(row, col) // 初始化图像
        {
            for (int j = RotImg.row - 1; j >= 0; j--)
            {
                for (int i = 0; i <= RotImg.col - 1; i++)
                {
                    cin >> RotImg.ImgData[i][j];
                }
            }
        }

        /* 获取旋转后的图片。 */
        MatrixImg getRotImg()
        {
            return RotImg;
        }
    };

    /* 修改RGB图像的值。 */
    void changeRGBImg(RGBImg &img, int x, int y, RGB color)
    {
        if (x >= 0 && x < img.row && y >= 0 && y < img.col)
        {
            img.ImgData[x][y] = color;
        }
        else
        {
            throw out_of_range("Index out of range");
        }
    }

    /* 判断RGB图像是否对称。 */
    bool isSymmetric(const RGBImg &img)
    {
        for (int i = 0; i < img.row; i++)
        {
            for (int j = 0; j < img.col / 2; j++)
            {
                if (img.ImgData[i][j] != img.ImgData[i][img.col - j - 1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

using namespace ImgProc;

int main()
{
    int row, col;
    cin >> row >> col;
    RGBImg img(row, col);

    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        int x, y;
        int channel_num;
        int add_value;
        cin >> x >> y >> channel_num >> add_value;

        x--, y--;                      // 转换为0-indexed
        RGB color = img.ImgData[x][y]; // 获取当前像素的颜色
        switch (channel_num)
        {
        case 1:
            color.set_R(color.R + add_value);
            break;
        case 2:
            color.set_G(color.G + add_value);
            break;
        case 3:
            color.set_B(color.B + add_value);
            break;
        default:
            break;
        }

        changeRGBImg(img, x, y, color); // 修改像素的颜色
        if (isSymmetric(img))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}