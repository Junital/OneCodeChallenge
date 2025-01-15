/*****************************************************************
 * 题目：[APC001] A - CT
 * 描述：压缩毛巾，遇水长宽高增加一厘米，问最后的体积。
 * 思路：构造三维立体。
 * 对象：Sphere模拟球体，Cube模拟立方体，Cuboid模拟长方体。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long // 定义长整型

template <typename T>
class ThreeDimension
{
private:
public:
    virtual T get_vol() = 0;  // 体积
    virtual T get_surf() = 0; // 表面积
};

template <typename T>
class Sphere : public ThreeDimension<T>
{
private:
    const double pi = 3.141593; // 定义圆周率
    T Radius;                   // 半径

public:
    /* 初始化，输入半径。 */
    Sphere(T r) : Radius(r) {}

    /* 计算体积。 */
    T get_vol() override
    {
        return 4.0 / 3 * pi * Radius * Radius * Radius;
    }

    /* 计算表面积。 */
    T get_surf() override
    {
        return 4.0 * pi * Radius * Radius;
    }
};

template <typename T>
class Cuboid : public ThreeDimension<T>
{
private:
    T Height;
    T Length;
    T Width;

public:
    Cuboid(T height, T length, T width)
        : Height(height), Length(length), Width(width) {}

    /* 计算表面积。 */
    T get_surf() override
    {
        return Width * Length * 2 +
               Length * Height * 2 +
               Width * Height * 2;
    }

    /* 计算体积。 */
    T get_vol() override
    {
        return Height * Length * Width;
    }

    /* 计算体积（取模）。 */
    T get_vol(T Mod)
    {
        static_assert(std::is_same<T, int>::value || std::is_same<T, long long>::value,
                      "T must be int or long long");
        return (((ll)Length % Mod *
                 (ll)Width % Mod) %
                Mod) *
               ((ll)Height % Mod) % Mod;
    }
};

template <typename T>
class Cube : public Cuboid<T>
{
private:
    T Edge;

public:
    /* 初始化，输入边长。 */
    Cube(T edge) : Cuboid<T>(edge, edge, edge), Edge(edge) {}

    /* 获取边长 */
    T getEdge() const
    {
        return Edge;
    }
};

int main()
{
    const int Mod = 988444333;
    int length, width, height, k;
    cin >> length >> width >> height >> k;

    Cuboid<int> c(length + k, width + k, height + k);
    cout << c.get_vol(Mod) << endl;
    return 0;
}