/************************************************************
 * 题目：【深基2.例8】再分肥宅水
 * 要求：输入饮料的容量和饮用的人数，输出每个人分得的饮料以及每人两个杯子一共需要多少个杯子。
 * 作者：Junital
 * 思路：简单的除法和乘法
 * 函数：ShareCode输出每人分得的饮料容量，GrabCup输出需要多少个杯子
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define CUPSPERPERSON 2

/* 输入总共的饮料容量和人数，通过除法输出每人分得的饮料容量 */
double ShareCode(double total_code, int person_num)
{
    return total_code / person_num; // 除法
}

/* 输入人数，输出总共需要的杯子 */
int GrabCup(int person_num)
{
    return person_num * CUPSPERPERSON;
}

int main()
{
    double total_code; // 总共的饮料容量
    int person_num;    // 人数

    scanf("%lf%d", &total_code, &person_num);

    printf("%.3f\n%d\n", ShareCode(total_code, person_num),
           GrabCup(person_num));
    return 0;
}