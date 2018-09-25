#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <algorithm>

namespace meituan
{
	using namespace std;
	void dierti()
	{
		int n = 0, k = 0, t = 0;
		int count = 0;
		cin >> n >> k >> t;
		vector<int> val(n);
		for (int i = 0; i < n; i++)
		{
			cin >> val[i];
		}
		if (k > n || t > k)
		{
			cout << 0 << endl;
			return;
		}
		for (int i = 0; i <= n - k; i++)
		{
			map<int, int> record;
			for (int j = i; j < i + k; j++)
			{
				record[val[j]] ++;
				if (record[val[j]] >= t)
				{
					count++;
					break;
				}
			}
		}
		cout << count;
	}
};

