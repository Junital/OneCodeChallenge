/*****************************************************************
 * 题目：[语言月赛 202407] true
 * 描述：将一个属性放大十倍，一个缩小十倍，和为10000。
 * 思路：简单乘除加减。
 * 对象：KingAttribute模拟国王属性。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class KingAttribute
{
private:
    const int scale = 10;  // 缩小放大规模
    const int sum = 10000; // 三者之和

public:
    /* 输入两个属性的变异值，输出三个原来的属性。 */
    void recover(int A, int B)
    {
        A /= scale;
        B *= scale;
        int C = sum - A - B;
        cout << A << " " << B << " " << C << endl;
    }
};

int main()
{
    KingAttribute ka;

    int a, b;
    cin >> a >> b;

    ka.recover(a, b);
    return 0;
}
