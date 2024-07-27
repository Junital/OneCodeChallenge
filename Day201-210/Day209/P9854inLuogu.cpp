/***********************************************
 * 题目：[CCC 2008 J1] Body Mass Index
 * 描述：输入身高、体重，判断是否肥胖。
 * 思路：简单计算。
 * 对象：BMI计算BMI值，并提供上下限。
 * 注意：注意精度。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

class BMI
{
public:
    const double HighNormal = 25;
    const double LowNormal = 18.5;

    double Calculate(double Weight, double Height)
    {
        return Weight / (Height * Height);
    }
};

int main()
{
    BMI B;
    double weight, height;
    cin >> weight >> height;

    double bmi = B.Calculate(weight, height);

    if (bmi >= B.HighNormal)
    {
        // cout << bmi << endl;
        cout << "Overweight" << endl;
    }
    else if (bmi < B.LowNormal)
    {
        cout << "Underweight" << endl;
    }
    else
    {
        cout << "Normal weight" << endl;
    }

    return 0;
}