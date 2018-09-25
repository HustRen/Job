#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <iterator>
#include <map>
namespace
{
	using namespace std;
	struct Range
	{
		int start;
		int end;
		Range() {}
		Range(int s, int e) { start = s; end = e; }
	};
	void findsub()
	{
		int n;
		cin >> n;
		vector<int> nums(n, 0);
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
			m[nums[i]]++;
		}
		vector<Range> ans;
		int start = 0, end = n - 1;
		while (end  > 0 && m[nums[end]] > 1)
		{
			m[nums[end]]--;
			end--;
		}
		while (start < end && m[nums[start]] > 1)
		{
			m[nums[start]]--;
			start++;
		}
		ans.push_back(Range(start, end));
		for (int i = start, j = end; j < n - 1; i++, j++)
		{
			if (nums[j + 1] == nums[i])
				ans.push_back(Range(i + 1, j + 1));
			else
				break;
		}
		int count = ans.size();
		int range = ans[0].start - ans[0].end + 1;
		cout << range << " " << count << endl;
		for (int i = 0; i < count; i++)
			cout << "[" << ans[i].start + 1 << "£¬" << ans[i].end + 1 << "] ";
	}
}