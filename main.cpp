// job.cpp : 定义控制台应用程序的入口点。
//
//#include<bits/stdc++.h>
#include "stdafx.h"
#include <iostream>
#include "algorithm.h"
#include <math.h>
#include "selectionandsort.h"
#include<sstream>
#include "netease.h"
#include<set> 
#include <map>
#include <vector>
#include "tencent.h"
#include"BiTree.h"
#include"offer.h"
#include <queue>
#include"oppo.h"
using namespace std;
using namespace oppo;

int covert(int base, string nums)
{
	int ans = 0;
	int len = nums.length();
	if (len == 0)
		return -1;
	int flage = 1;
	if (nums[len - 1] == '-')
	{
		flage = -1;
		len = len - 1;
	}
	for (int i = len - 1; i >= 0; i--)
	{
		ans += (nums[i] - '0') * (int)pow(base, len - 1 - i);
	}
	return flage * ans;
}

void findAns(vector<string>& nums)
{
	int len = nums.size();
	vector<int> num(len, -1);
	map<int, int> m;
	for (int i = 0; i < len; i++)
	{
		int pos = nums[i].find("#");
		string strBase = nums[i].substr(0, pos);
		int base = atoi(strBase.c_str());
		string strNum = nums[i].substr(pos + 1, len - pos);
		int ans = covert(base, strNum);
		num[i] = ans;
		m[ans] ++;
	}
	int flage = false;
	for (int i = 0; i < len; i++)
	{
		if (m[num[i]] == 1)
		{
			cout << nums[i] << endl;
			flage = true;
		}
	}
	if (flage == false)
		cout << "None";
}

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int findMaxCapacity(vector < int > array, int m) 
{
	priority_queue<int, vector<int>, greater<int>> q;
	int len = array.size();
	for (int i = 0; i < len; i++)
	{
		q.push(array[i]);
	}
	while(m >= 0)
	{ 
		int min = q.top();
		q.pop();
		q.push(min + 1);
		m--;
	}
	return q.top() * len;
}
/******************************结束写代码******************************/


int main() {
	int res;

	int _array_size = 0;
	cin >> _array_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int> _array;
	int _array_item;
	for (int _array_i = 0; _array_i<_array_size; _array_i++) {
		cin >> _array_item;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		_array.push_back(_array_item);
	}


	int _m;
	cin >> _m;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');



	res = findMaxCapacity(_array, _m);
	cout << res << endl;

	return 0;

}



