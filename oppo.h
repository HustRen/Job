#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <iterator>

namespace oppo
{
	using namespace std;
	void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
	{
		std::string::size_type pos1, pos2;
		pos2 = s.find(c);
		pos1 = 0;
		while (std::string::npos != pos2)
		{
			v.push_back(s.substr(pos1, pos2 - pos1));

			pos1 = pos2 + c.size();
			pos2 = s.find(c, pos1);
		}
		if (pos1 != s.length())
			v.push_back(s.substr(pos1));
	}

	struct node
	{
		int val;
		int index;
		node() {};
		node(int v, int i) { val = v; index = i; };
		friend bool operator < (node a, node b)
		{
			return a.val > b.val;    //结构体中，x小的优先级高     
		}
	};

	int findK(string nums, int k)
	{
		priority_queue <node> q;
		vector<string> data;
		SplitString(nums, data, ",");
		for (int i = 0; i < data.size(); i++)
		{
			int d = atoi(data[i].c_str());
			if (q.size() < k)
				q.push(node(d, i));
			else
			{
				node t = q.top();
				if (t.val < d)
				{
					q.pop();
					q.push(node(d, i));
				}
			}
		}
		node t;
		t = q.top();
		return (t.index + 1);
	}

	void revertTree(vector<int>& tree)
	{
		sort(tree.begin(), tree.end(), less<int>());
		copy(tree.begin(), tree.end() - 1, ostream_iterator<int>(cout, " "));
		cout << tree[tree.size() - 1];
	}
}