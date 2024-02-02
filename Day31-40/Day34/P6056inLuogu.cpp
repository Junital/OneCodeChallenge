/***********************************************
 * 题目：[加油武汉] SIR 模型
 * 描述：模拟疫情的感染，有一定比例易感者会变成感染者，也有一定比例感染者会变成恢复者。
 * 思路：模拟感染。
 * 对象：Cov19作为病毒模型。
 * 注意：要连续推导递归感染者和易感者，还有注意输出问题。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

class Cov19
{
private:
    double InfectRate;
    double RecoverRate;
    double InitSuscept;
    double InitInfect;

public:
    /* 初始化输入初始易感者人数、感染者人数、感染系数、恢复系数。 */
    Cov19(double is, double ii, double ir, double rr)
    {
        InfectRate = ir;
        RecoverRate = rr;
        InitSuscept = is;
        InitInfect = ii;
    }

    /* 输出某一天的易感染人数、感染者人数、恢复者人数。 */
    void printSomeday(int Days)
    {
        /* 三个初始状态。 */
        int Suscept = InitSuscept;
        int Infect = InitInfect;
        int Recover = 0;

        for (int day = 1; day <= Days; day++)
        {
            double infect = ceil(InfectRate * Suscept * Infect); // 感染人数
            double recover = ceil(RecoverRate * Infect);         // 治愈人数
            infect = min(infect, (double)Suscept);

            /* 治愈人数转换 */
            Recover += recover;
            Infect -= recover;

            /* 感染人数转换 */
            Suscept -= infect;
            Infect += infect;
        }

        cout << Suscept << " " << Infect << " " << Recover << endl;
    }
};

int main()
{
    double Suscept, Infect, InfectRate, RecoverRate;
    int Days;

    cin >> Suscept >> Infect >> Days;
    cin >> InfectRate >> RecoverRate;

    Cov19 cov(Suscept, Infect, InfectRate, RecoverRate);
    cov.printSomeday(Days);
    return 0;
}
