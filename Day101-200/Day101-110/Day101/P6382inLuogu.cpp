/***********************************************
 * 题目：『MdOI R2』Car
 * 描述：根据车牌号是否是本地的、以及尾号判断限行。
 * 思路：模拟。
 * 对象：CarLimit模拟限号。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class CarLimit
{
private:
    const int RegionLen = 3;         // 地区有三个字母
    const int IdxLen = 5;            // 识别码有5位。
    const string LocalRegin = "MDA"; // 本地区域编码
    const int WeekDay = 5;           // 工作日为5天
    map<int, int> LimitMap;          // 尾号与函数之间的映射

    const int Monday = 0;
    const int Tuesday = 1;
    const int Wednesday = 2;
    const int Thursday = 3;
    const int Friday = 4;

    void AllLimit(vector<bool> &limit)
    {
        int len = limit.size();

        assert(len == WeekDay);

        rep(i, 0, len - 1)
        {
            limit[i] = true;
        }
    }

    void SingleLimit(vector<bool> &limit, int Day)
    {
        int len = limit.size();

        assert(len == WeekDay);

        limit[Day] = true;
    }

    void Init()
    {
        LimitMap[0] = Friday;
        LimitMap[1] = Monday;
        LimitMap[2] = Tuesday;
        LimitMap[3] = Wednesday;
        LimitMap[4] = Thursday;
        LimitMap[5] = Friday;
        LimitMap[6] = Thursday;
        LimitMap[7] = Wednesday;
        LimitMap[8] = Tuesday;
        LimitMap[9] = Monday;
    }

public:
    /* 初始化 */
    CarLimit()
    {
        Init();
    }

    /* 输入车牌号字符串，输出限行序列。 */
    vector<bool> Limit(string Car)
    {
        int carlen = Car.size();
        assert(carlen == RegionLen + IdxLen);

        vector<bool> CannotDrive(WeekDay, false);
        string Region = Car.substr(0, RegionLen);

        /* 不属于本地，那么全不能通行 */
        if (Region != LocalRegin)
        {
            AllLimit(CannotDrive);
            return CannotDrive;
        }

        /* 找到 */
        string Idx = Car.substr(RegionLen, IdxLen);
        reverse(Idx.begin(), Idx.end());
        int Num = -1;

        for (auto ch : Idx)
        {
            if (ch >= '0' && ch <= '9')
            {
                Num = ch - '0';
                break;
            }
        }

        // cout << Num << endl;

        if (Num != -1)
        {
            SingleLimit(CannotDrive, LimitMap[Num]);
        }

        return CannotDrive;
    }
};

int main()
{
    CarLimit cl;

    string car;
    cin >> car;

    vector<bool> limit = cl.Limit(car);
    for (auto l : limit)
    {
        if (l)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        cout << " ";
    }
    cout << endl;
    return 0;
}
