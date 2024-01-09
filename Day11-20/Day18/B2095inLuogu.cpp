/************************************************************
 * 题目：白细胞计数
 * 要求：输入一组数据，输出去除最大值和最小值后的平均值，以及其他数离平均值的最大距离。（结果保留两位小数）
 * 作者：Junital
 * 思路：无
 * 函数：ScienceCom用于计算数据，DropMinMax用于去除最大值和最小值。
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速循环

/* 输入一个数组，之后会删除其最大最小的值 */
void DropMinMax(vector<double> &Data)
{
    vector<double> dropedMinData; // 用于存放去除最小值的数组
    double MinData = Data[0];     // 目前最小的数据，初始值设为第一个数据
    int DataSize = Data.size();   // 数据的大小

    /* 遍历从第二个开始的所有数据，删除最小的 */
    rep(i, 1, DataSize - 1)
    {
        if (Data[i] < MinData) // 如果小于目前最小的数据
        {
            dropedMinData.push_back(MinData); // 目前最小的数据可以加入新数组
            MinData = Data[i];                // 更新最小的数据
        }
        else // 如果不小于目前最小的数据
        {
            dropedMinData.push_back(Data[i]);
        }
    }

    /* 同样的方法更新数据和最大数据 */
    Data = dropedMinData;
    DataSize = Data.size();
    double MaxData = Data[0];
    vector<double> dropedMinMaxData;

    /* 遍历数组，目的是去除最大的数据 */
    rep(i, 1, DataSize - 1)
    {
        if (Data[i] > MaxData) // 如果数据目前是最大的
        {
            dropedMinMaxData.push_back(MaxData);
            MaxData = Data[i];
        }
        else // 如果不是最大的
        {
            dropedMinMaxData.push_back(Data[i]);
        }
    }

    Data = dropedMinMaxData;
}

void ScienceCom(vector<double> Data)
{
    DropMinMax(Data); // 去除最小值和最大值

    double DataSum = 0;         // 数据之和
    double DataAvg;             // 数据平均数
    double DataDev = 0;         // 数据的最大偏差
    int DataSize = Data.size(); // 数组大小

    /* 求和 */
    for (auto data : Data)
    {
        DataSum += data;
    }

    DataAvg = DataSum / DataSize; // 计算平均值

    /* 求偏差 */
    for (auto data : Data)
    {
        DataDev = max(DataDev, abs(data - DataAvg)); // 将目前的最大偏差和新的偏差作MAX
    }

    cout << fixed << setprecision(2) << DataAvg << " " << DataDev << endl; // 输出，保留两位小数
}

int main()
{
    int n;               // 数据的数量
    vector<double> data; // 存储数据
    cin >> n;

    rep(i, 1, n)
    {
        double d; // 暂时存放单个数据元素
        cin >> d;
        data.push_back(d);
    }

    ScienceCom(data);
    return 0;
}
