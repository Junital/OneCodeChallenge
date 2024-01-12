/******************************************************
 * 题目：不高兴的津津（升级版）
 * 描述：类似一个影响计算，每天的不开心程度为上一天的不开心程度减8。
 * 求出几天后的不高兴程度。
 * 思路：模拟即可。
 * 函数：CalUnhappy计算不开心程度。
 ******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define UNHPYTHRES 8							  // 不开心程度的阈值
#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速循环

/* 输入一个元素为两个整型的数组，输出计算得到的不开心程度和。 */
int CalUnhappy(vector<pair<int, int>> Schedule)
{
	int Unhappy = 0;  // 初始不开心值为0
	int SumUnhpy = 0; // 统计所有不开心值和

	for (auto DaySched : Schedule)
	{
		int ClassSched = DaySched.first;							  // 获得上课时间
		int ExtracuSched = DaySched.second;							  // 获得补习班时间
		Unhappy = Unhappy + (ClassSched + ExtracuSched) - UNHPYTHRES; // 迭代计算每天的不开心程度
		SumUnhpy += Unhappy;
	}

	return SumUnhpy;
}

int main()
{
	int SchedSize;					 // 一共有几天
	vector<pair<int, int>> Schedule; // 每个元素为（上学时间，课外补习时间）二元组

	cin >> SchedSize;
	rep(i, 1, SchedSize)
	{
		int ClassSched;
		int ExtracuSched;
		cin >> ClassSched >> ExtracuSched;
		Schedule.push_back(make_pair(ClassSched, ExtracuSched));
	}

	cout << CalUnhappy(Schedule) << endl;

	return 0;
}