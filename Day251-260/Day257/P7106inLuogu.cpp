/*****************************************************************
 * 题目：双生独白
 * 描述：给定RGB三色，给出其反色。
 * 思路：先转换十六进制，然后转换。
 * 对象：RGBColor模拟彩色。
 * 注意：注意加入可拓展模块。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class RGBColor
{
private:
    string RGB;           // 字符串
    int R, G, B;          // 三色值
    const int FULL = 255; // 满色为255

    /* 解析字符串 */
    void parse()
    {
        R = stoi(RGB.substr(1, 2), nullptr, 16);
        G = stoi(RGB.substr(3, 2), nullptr, 16);
        B = stoi(RGB.substr(5, 2), nullptr, 16);
    }

    /* 计算字符串 */
    string get_string(int r, int g, int b)
    {
        stringstream r_stream;
        r_stream << uppercase << setw(2) << setfill('0') << hex << r;
        string r_str = r_stream.str();

        stringstream g_stream;
        g_stream << uppercase << setw(2) << setfill('0') << hex << g;
        string g_str = g_stream.str();

        stringstream b_stream;
        b_stream << uppercase << setw(2) << setfill('0') << hex << b;
        string b_str = b_stream.str();

        return "#" + r_str + g_str + b_str;
    }

public:
    /* 初始化，输入字符串 */
    RGBColor(string rgb) : RGB(rgb)
    {
        assert(rgb[0] == '#' && rgb.size() == 7);
        parse();
    }

    /* 重构取负数。 */
    RGBColor operator-()
    {
        int r = FULL - R;
        int g = FULL - G;
        int b = FULL - B;

        return RGBColor(get_string(r, g, b));
    }

    /* 输出 */
    void print()
    {
        cout << RGB << endl;
    }
};

int main()
{
    string rgb;
    cin >> rgb;

    RGBColor c1(rgb);
    RGBColor c2 = -c1;

    c2.print();
    return 0;
}