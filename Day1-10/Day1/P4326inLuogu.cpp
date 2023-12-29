/************************************************************
 * 题目：[COCI2006-2007#1] Herman
 * 要求：出租车几何学
 * 作者：Junital
 * 函数：TaxiGeometry用于计算出租车几何学的圆面积，NormalGeometry用于计算欧氏几何圆面积
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

const double pi = 3.1415926535898; // 精度有问题，重新增加了几位pi

double NormalGeometry(int r) // 欧式几何的计算公式为 pi * r * r
{
    int r_square = r * r; // 数据大小最多为10^8，不会有问题
    return pi * r_square;
}

double TaxiGeometry(int r) // 出租车几何的计算公式为 2 * r * r，
                           // 计算过程可以看一下同名svg文件
{
    int r_square = r * r;
    return 2 * r_square;
}

int main()
{
    int r; // 用于输入半径
    scanf("%d", &r);
    printf("%f\n", NormalGeometry(r));
    printf("%f\n", TaxiGeometry(r));
}