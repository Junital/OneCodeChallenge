/******************************************************
 * 题目：小鱼的数字游戏
 * 描述：输入一串数据，然后反着输出出来。
 * 思路：做一个栈即可。
 * 函数：ReverseIO用于输入数据，输出反向的数据。
 ******************************************************/

#include <bits/stdc++.h>

using namespace std;

void ReverseIO()
{
	stack<int> st; // 用栈模拟。
	int num;	   // 用于暂时存放每一个数。

	/* 压栈 */
	do
	{
		cin >> num;
		if (num != 0)
		{
			st.push(num);
		}
	} while (num != 0);

	/* 每次输出栈顶 */
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

int main()
{
	ReverseIO();
	return 0;
}