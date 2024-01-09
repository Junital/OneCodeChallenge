/************************************************************
 * 题目：地球人口承载力估计
 * 要求：地球的资源可供x亿人生活a年，或供y亿人生活b年。计算能可持续养活多少人。
 * 作者：Junital
 * 思路：计算每年增长的新生资源，新生资源就是最多能养活的人数（如果新生资源小于养活人数，那么总有一天会耗尽的。
 * 函数：CompSusPeopNum计算可持续养活的人口
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

/* 输入人数1和对应的养活年数，输入人数2和对应的养活年数 */
double CompSusPeopNum(int peopleNum1, int year1, int peopleNum2, int year2)
{
    /* 计算每年增长的新生资源(人/年) */
    double newResPerY = abs((double)(peopleNum1 * year1 - peopleNum2 * year2)) / abs((double)(year1 - year2)); // abs(y * b - x * a) / abs(b - a)

    return newResPerY;
}

int main()
{
    int peopleNum1, year1, peopleNum2, year2;

    scanf("%d%d%d%d", &peopleNum1, &year1, &peopleNum2, &year2);

    printf("%.2f\n", CompSusPeopNum(peopleNum1, year1, peopleNum2, year2)); // 计算可持续人口
    return 0;
}
