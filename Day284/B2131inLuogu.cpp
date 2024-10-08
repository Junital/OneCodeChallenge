/*********************************************
 * 题目：甲流病人初筛
 * 描述：体温大于等于37.5，并且咳嗽的人初筛为甲流患者。
 * 思路：简单判断。
 * 对象：FluA模拟甲流。
 * 注意：增加可拓展性。
 ********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 这里修改病人信息。 */
struct PatientInfo
{
    string name;
    double temp; // 体温
    bool cough;  // 是否咳嗽
};

/* 这里修改判断函数。 */
bool judge(PatientInfo pi)
{
    return pi.temp >= 37.5 && pi.cough == true;
}

class FluA
{
private:
public:
    /* 初筛，输入信息数组，输出病人数组。 */
    vector<PatientInfo> InitScreen(vector<PatientInfo> Arr,
                                   bool (*judge)(PatientInfo))
    {
        vector<PatientInfo> sick;
        for (auto patient : Arr)
        {
            if (judge(patient))
            {
                sick.push_back(patient);
            }
        }

        return sick;
    }
};

int main()
{
    int num;
    cin >> num;

    vector<PatientInfo> arr(num);
    FluA fa;

    rep(i, 0, num - 1)
    {
        cin >> arr[i].name >> arr[i].temp >> arr[i].cough;
    }
    vector<PatientInfo> ill = fa.InitScreen(arr, &judge);
    for (auto i : ill)
    {
        cout << i.name << endl;
    }
    cout << ill.size() << endl;
    return 0;
}
