#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <queue>
#include <map>
#include <list>
#include <stack>

namespace zjtd
{
	using namespace std;

	int substr(char* input)
	{
		int len = strlen(input);
		char *p = input;
		char *substring = p;        //当前子串  
		int length = 0;                //当前子串长度       
		int maxLength = 0;                //已经找到的最大子串长度  


		char* position[256];      // 遍历字符串过程中，字符最后一次出现的位置  
		memset(position, 0, 256 * sizeof(char *));

		char ch;    //  
		for (int i = 0; i < len; i++)
		{
			ch = *p;
			if (position[ch] < substring)//字符在当前子串首次出现  
			{
				length++;
				if (length > maxLength)
				{
					maxLength = length;
				}
			}
			else
			{
				substring = position[ch] + 1;    //当前子串从该字符上次出现的位置后面开始  
				length = p - position[ch];
			}

			position[ch] = p; // 保存字符的位置  
			p++;
		}
		return maxLength;
	}

	void markAllRelation(int current, int m, map<int, vector<int>> &relation, vector<int> &mark)
	{
		queue<int> seed;
		seed.push(current);
		while (!seed.empty())
		{
			vector<int> firends = relation[seed.front()];
			seed.pop();
			for (int i = 0; i < firends.size(); i++)
			{
				if (mark[firends[i]] != -1) continue;

				seed.push(firends[i]);
				mark[firends[i]] = m;
			}
		}
	}

	void fixRelation(map<int, vector<int>> &relation, int n)
	{
		for (int i = 1; i <= n; i++)
		{
			vector<int> firends = relation[i];
			for (int j = 0; j < firends.size(); j++)
			{
				relation[firends[j]].push_back(i);
			}
		}
	}

	int subgroups(map<int, vector<int>> &relation, int n)
	{
		int m = 0;
		vector<int> mark(n + 1, -1);
		for (int i = 1; i <= n; i++)
		{
			if (mark[i] != -1)  continue;

			mark[i] = m;
			markAllRelation(i, m, relation, mark);
			m++;
		}
		return m;
	}

	bool isSame(string& str1, string& str2)
	{
		int len = str1.size();
		if (len == str2.size()) return false;

		string str = str2 + str2;
		int j = 0, count, begin;
		for (int i = 0; i < 2 * len; i++)
		{
			if (str1[j] == str[i])
			{
				begin = i;
				count = 1;
				while (str1[++j] == str[++i])
					count++;
				if (count == len)
					return true;
				else
				{
					j = 0;
					i = begin;
				}
			}
		}
		return false;
	}

	void CutWord(string& scr, map<string, int>& dict)
	{
		int len = scr.length();
		int start = 0;
		vector<string> ans;
		for (int i = min(start + 50, len); i > start; i--)
		{
			string word = scr.substr(start, i - start);
			if (dict.find(word) != dict.end())
			{
				start = start + dict[word];
				ans.push_back(word);
				i = min(start + 50, len + 1);
			}
		}
		for_each(ans.begin(), ans.end() - 1, [](string s) {cout << s << " "; });
		cout << ans[ans.size() - 1];
	}

	int longestSubstr(string A)
	{
		vector<int> m(256, -1);
		int n = A.length();

		int pre = -1, maxLen = 0;

		for (int i = 0; i < n; i++)
		{
			pre = max(pre, m[A[i]]);
			maxLen = max(maxLen, i - pre);
			m[A[i]] = i;
		}

		return maxLen;
	}

	int findTream(vector<vector<int>> &m, int n)
	{
		struct seed
		{
			int x;
			int y;
			seed(int i, int j) { x = i; y = j; }
			seed() {};
			//seed operator+(seed& a) { seed temp(x + a.x, y + a.y); return temp; };
		};
		seed dict[4] = { seed(-1, 0), seed(1, 0), seed(0, -1), seed(0, 1) };
		vector<vector<int>> visit(n, vector<int>(n, 0));
		int counts = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (m[i][j] != 0 && visit[i][j] == 0)
				{
					stack<seed> stacks;
					counts = counts + 1;
					stacks.push(seed(i, j));
					while (!stacks.empty())
					{
						seed temp = stacks.top(); stacks.pop();
						visit[temp.x][temp.y] = counts;
						for (int d = 0; d < 4; d++)
						{
							seed s = dict[d];
							int lx = temp.x + s.x;
							int ly = temp.y + s.y;
							if ((lx < n && lx >= 0) && (ly < n && ly >= 0) && m[lx][ly] != 0 && visit[lx][ly] == 0)
							{
								stacks.push(seed(lx, ly));
							}
						}
					}
				}
			}

		}
		return counts;
	}

	int findHot(map<int, vector<int>> &relation)
	{
		return 0;
	}

	bool isCorrect(string s)
	{
		if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0'))
			return false;
		int res = atoi(s.c_str());
		return res <= 255 && res >= 0;
	}

	void restore(list<string> &res, string s, int k, string out)
	{
		if (k == 0)
		{
			if (s.empty()) res.push_back(out);
		}
		else
		{
			for (int i = 1; i <= 3; ++i)
			{
				if (s.size() >= i && isCorrect(s.substr(0, i)))
				{
					if (k == 1)
						restore(res, s.substr(i), k - 1, out + s.substr(0, i));
					else
						restore(res, s.substr(i), k - 1, out + s.substr(0, i) + ".");
				}
			}
		}
	}

	int restoreIp(string s)
	{
		list<string> res;
		restore(res, s, 4, "");
		return res.size();
	}

	struct info
	{
		vector<int> f;
		int count;
	};

	int findHot()
	{
		int N, M;
		cin >> N >> M;

		vector<vector<int>> relation(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) relation[i][i] = 1;

		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			relation[--a][--b] = 1;
			for (int j = 0; j < N; j++)
			{
				if (relation[j][a] == 1)  relation[j][b] = 1;
			}
		}

		int count = 0;
		for (int i = 0; i < N; i++)
		{
			int count = 0;
			for (int i = 0; i < N; i++)
			{
				int j = 0;
				for (j = 0; j < N; j++)
				{
					if (relation[j][i] == 0)
						break;
				}

				if (j == N)
					++count;
			}
		}
		std::cout << count;
	}
};

