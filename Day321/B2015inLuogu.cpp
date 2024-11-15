/*****************************************************************
 * 题目：计算并联电阻的阻值
 * 描述：计算两个电阻并联后的阻值。
 * 思路：重构电阻的并、串，计算阻值。
 * 对象：Resistor模拟电阻。
 * 注意：注意保留小数点。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Resistor
{
private:
    double Impedance;

public:
    /* 初始化，输入阻抗。 */
    Resistor(double imp) : Impedance(imp) {}

    /* 打印阻抗，保留两位小数。 */
    void print()
    {
        cout << fixed << setprecision(2) << Impedance << endl;
    }

    /* 重构与 */
    Resistor operator&(Resistor &other)
    {
        return Resistor(this->Impedance + other.Impedance);
    }

    /* 重构或。 */
    Resistor operator|(Resistor &other)
    {
        double this_inv = 1.0 / this->Impedance;
        double other_inv = 1.0 / other.Impedance;

        return Resistor(1.0 / (this_inv + other_inv));
    }
};

int main()
{
    double a, b;
    cin >> a >> b;

    Resistor A(a), B(b);

    Resistor C = A | B;
    C.print();
    return 0;
}
