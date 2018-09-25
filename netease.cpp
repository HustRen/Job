#include "stdafx.h"
#include "netease.h"
#include <iostream>
#include <algorithm>
#include <xfunctional>
#include <istream>
#include <string>
#include <set>
#include <iterator>
#include <map>
#include <queue>

namespace netease
{
	using std::string;
	using std::cout;
	using std::endl;
	bool compare(const pair<int, int> &a, const pair<int, int> &b)
	{
		return a.first < b.first;
	}

	void mostMatchWork(vector<pair<int, int>> &workInfo, vector<int> &workers)
	{
		std::stable_sort(workInfo.begin(), workInfo.end(), compare);
		int length = workers.size();
		for (int i = 0; i < length; i++)
		{
			std::cout << matchWork(workInfo, workers[i]) << std::endl;
		}
	}

	int matchWork(vector<pair<int, int>> &workInfo, int worker)
	{
		int length = workInfo.size();
		int i = 0;
		int max = -100;
		while (i < length && workInfo[i].first <= worker)
		{
			if (workInfo[i].second > max)
			{
				max = workInfo[i].second;
			}
			i ++;
		}
		return max;
	}

	void mostMatchWorkTest()
	{
		using std::cin;
		vector<pair<int, int>> workInfo;
		vector<int> workers;
		int workNum, workerNum;
		while (cin >> workNum >> workerNum)
		{
			workInfo.resize(workNum);
			workers.resize(workerNum);

			pair<int, int> temp;
			for (int i = 0; i < workNum; i++)
			{
				cin >> temp.first >> temp.second;
				workInfo[i] = temp;
			}

			for (int i = 0; i < workerNum; i++)
			{
				cin >> workers[i];
			}

			mostMatchWork(workInfo, workers);
			std::sort(workers.begin(), workers.end(), std::greater<int>());
			
		}
	}

	void pingduoduo()
	{
		char c;
		std::multiset<int> woodStick;
		while ((c = getchar()) != '\n')
		{
			if (c != ' ')//把这句判断条件改动  
			{
				int temp = 0;
				ungetc(c, stdin);
				std::cin >> temp;
				woodStick.insert(temp);
			}
		}
		while (woodStick.size() > 0)
		{
			int size = woodStick.size();
			int min = *std::min_element(woodStick.begin(), woodStick.end());
			woodStick.erase(min);
			std::cout << size << std::endl;
		}	
	}

	void findTeamMenber()
	{
		int T = 0;
		while (std::cin >> T)
		{
			std::vector<int> ans(T, 0);
			for (int i = 0; i < T; i++)
			{
				int N = 0, X = 0, Y = 0;
				std::cin >> N >> X >> Y;
				ans[i] = findCore(N, X, Y);
			}
			for (int i = 0; i < T; i++)
			{
				std::cout << ans[i] << std::endl;
			}
		}
	}

	int  findCore(int N, int X, int Y)
	{
		std::priority_queue<int> forward, mid;
		int fCount = 0, mCount = 0;
		std::vector<int> temp;
		for (int j = 0; j < N; j++)
		{
			int f = 0, m = 0;
			std::cin >> f >> m;
			if (f == m)
				temp.push_back(-1 * f);
			else if (f > m)
			{
				forward.push(-1 * f);
				if (fCount < X)
					fCount++;
				else
					forward.pop();
			}
			else if (m > f)
			{
				if (mCount < Y)
					mCount++;
				else
					mid.pop();
			}
		}

		if (mCount < Y)
		{
			int dif = Y - mCount;
			if (dif > temp.size())
				return 0;

			std::sort(temp.begin(), temp.end());
			for (int index = 0; index < dif; index++)
			{
				mid.push(temp[index]);
				temp[index] = 0;
			}
		}
		/*else
		{
			if (temp.size() > 0)
			{
				for (int i = 0; i < temp.size(); i++)
				{
					if (mid.top() > * std::max_element(temp.begin(), temp.end()))
					{
						mid.push(temp[i]);
						mid.pop();
						temp[i] = 0;
					}
				}
			}
		}*/

		if (fCount < X)
		{
			int dif = X - fCount;
			if (dif > temp.size())
				return 0;

			std::sort(temp.begin(), temp.end());
			for (int index = 0; index < dif; index++)
				forward.push(-1 * temp[index]);
		}
		/*else
		{
			if (temp.size() > 0)
			{
				for (int i = 0; i < temp.size(); i++)
				{
					if (forward.top() > * std::max_element(temp.begin(), temp.end()))
					{
						forward.push(temp[i]);
						forward.pop();
					}
				}
			}
		}*/
		int fMin = -1 * forward.top();
		int mMin = -1 * mid.top();
		return std::min(mMin, fMin);
	}

	int getCommLen(std::string str1, std::string str2)
	{
		int i;
		for (i = 0; i < str1.size() && i < str2.size(); i++)
		{
			if (str1[i] != str2[i])
				break;
		}
		return i;
	}

	int findFriends(vector<vector<int>>& relation, int user)
	{
		int n = relation.size();
		vector<int> score(n, 0);
		int userFirends = relation[user].size();
		score[user] = -500;
		for (int i = 0; i < userFirends; i++)
		{
			score[relation[user][i]] = -200;
		}

		for (int i = 0; i < userFirends; i++)
		{
			int firend = relation[user][i];
			for (int j = 0; j < relation[firend].size(); j++)
			{
				score[relation[firend][j]] ++;
			}
		}
		int maxindex = 0;
		for (int i = 1; i < n; i++)
		{
			if (score[maxindex] < score[i])
			{
				maxindex = i;
			}
		}
		return score[maxindex] > 0 ? maxindex : -1;
	}

	vector<int> tax(vector<int>& m)
	{
		vector<int> taxs(m.size(), 0);
		for (int i = 0; i < m.size(); i++)
		{
			int current = m[i];
			float taxf = 0.0;
			current -= 5000;
			if (current > 0)
			{
				if (current < 3000)
				{
					taxf += current * 0.03;
				}
				else
				{
					taxf += 3000 * 0.03;
					current -= 3000;
					if (current < 9000)
					{
						taxf += current * 0.1;

					}
					else
					{
						taxf += 9000 * 0.1;
						current -= 9000;
						if (current < 13000)
						{
							taxf += current * 0.2;
						}
						else
						{
							taxf += 13000 * 0.2;
							current -= 13000;
							if (current < 10000)
							{
								taxf += current * 0.25;
							}
							else
							{
								taxf += 10000 * 0.25;
								current -= 10000;
								if (current < 20000)
								{
									taxf += current * 0.3;
								}
								else
								{
									taxf += 20000 * 0.3;
									current -= 20000;
									if (current < 25000)
									{
										taxf += current * 0.35;
									}
									else
									{
										taxf += 25000 * 0.35;
										current -= 25000;
										if (current > 0)
										{
											taxf += current * 0.45;
										}
									}
								}
							}
						}
					}
				}
			}
			int taxi = round(taxf);
			taxs[i] = taxi;
		}
		return taxs;
	}

	void printString(string str)
	{
		int len = str.length();
		int border = len / 4;
		for (int i = 0; i <= border; i++)
		{
			cout << str[i];
		}
		cout << endl;
		for (int i = 1; i < border; i++)
		{
			cout << str[len - i];
			int space = border - 1;
			while (space-- > 0)
				cout << " ";
			cout << str[border + i] << endl;
		}
		for (int i = 0; i <= border; i++)
		{
			cout << str[len - border - i];
		}
	}

	//int main()
	//{
	//	int n, k;
	//	while (cin >> n >> k)//注意while处理多个case
	//	{
	//		int temp = 0;
	//		for (int i = 0; i < k; i ++)
	//		{
	//			cin >> temp;
	//		}
	//		if (k >= 2 * n - 4)
	//			cout << "Yes";
	//		else
	//			cout << "No";
	//	}
	//
	//	string str;
	//	cin >> str;
	//	vector<string> strs;
	//	for (size_t i = 0; i < str.size(); i++) {
	//		strs.push_back(str.substr(i));
	//	}
	//	sort(strs.begin(), strs.end());
	//
	//	int maxLen = 0;
	//	for (int i = 0; i < strs.size() - 1; i++)
	//	{
	//		int len = getCommLen(strs[i], strs[i + 1]);
	//		if (len > maxLen)
	//			maxLen = len;
	//	}
	//	cout << maxLen << endl;
	//	return 0;
	//}
	using namespace std;

	void findPath(multimap<int, int> &m_sRelev, vector<double> &timeUsed,
		vector<int>& path, vector<vector<int> > &paths, int key, int &time, int &maxTime)
	{

		multimap<int, int>::iterator iter;
		time += timeUsed[key];
		path.push_back(key);

		if ((iter = m_sRelev.find(key)) != m_sRelev.end())
		{//有孩子
			int n = m_sRelev.count(key);
			for (int j = 0; j < n; ++j, ++iter)
			{
				findPath(m_sRelev, timeUsed, path, paths, iter->second, time, maxTime);
			}
		}
		else
		{//子节点
			paths.push_back(path);
			if (maxTime < time)
				maxTime = time;
		}

		time -= timeUsed[key];
		path.pop_back();
	}
	//int main()
	//{
	//	int numSystem, numRelev;
	//	while (cin >> numSystem >> numRelev) 
	//	{
	//		vector<double> timeUsed(numSystem + 1);//保存时间
	//		//bool* isHead = new bool[numSystem + 1];//该系统是否要依赖其它系统
	//		vector<bool> isHead(numSystem + 1, true);
	//		//memset(isHead, 1, numSystem + 1);//首先全部置为true
	//		multimap<int, int> m_sRelev;//依赖关系
	//		int maxTime = 0;
	//		vector<vector<int> > paths;
	//		for (int i = 1; i <= numSystem; ++i)
	//		{
	//			double time;
	//			cin >> time;
	//			timeUsed[i] = time;
	//		}
	//		for (int i = 0; i < numRelev; ++i)
	//		{
	//			int sysMaster, sysSlave;
	//			cin >> sysMaster >> sysSlave;
	//			m_sRelev.insert(make_pair(sysMaster, sysSlave));
	//			isHead[sysSlave] = false;//依赖其它系统，那么不能作为链路的开端
	//		}
	//
	//		for (int i = 1; i <= numSystem; ++i)
	//		{
	//			if (isHead[i]) 
	//			{//如果是链路的开端
	//				int time = 0;
	//				vector<int>path;
	//				findPath(m_sRelev, timeUsed, path, paths, i, time, maxTime);
	//			}
	//		}
	//		//delete[] isHead;
	//		cout << paths.size() << " " << maxTime << endl;
	//	}
	//
	//
	//	return 0;
	//}

	bool ismatch(string m, string num)
	{
		bool ans = false;
		int index = m.find_first_of('x');
		if (m.substr(0, index) == num.substr(0, index))
			ans = true;
		return ans;
	}

	vector<string> findPlace(map<string, string>& table, vector<string> &nums)
	{
		vector<string> place(nums.size(), "unknown");
		map<string, string>::iterator index;
		for (int i = 0; i < nums.size(); i++)
		{
			string num = nums[i];
			for (index = table.begin(); index != table.end(); index++)
			{
				pair<string, string> node = *index;
				if (ismatch(node.first, num))
				{
					place[i] = node.second;
					break;
				}
			}
		}
		return place;
	}

	bool inSpecial(char c)
	{
		string special = "!@#$%^&*()_-=+,.<>/?";
		int len = special.length();
		for (int i = 0; i < len; i++)
		{
			if (c == special[i])
				return true;
		}
		return false;
	}

	bool inLower(char c)
	{
		if (c >= 'a' && c <= 'z')
			return true;
		else
			return false;
	}

	bool inBiger(char c)
	{
		if (c >= 'A' && c <= 'Z')
			return true;
		else
			return false;
	}

	bool inNum(char c)
	{
		if (c >= '0' && c <= '9')
			return true;
		else
			return false;
	}

	bool order2(string& pass)
	{
		bool s = false, l = false, b = false, n = false;
		for (int i = 0; i < pass.length(); i++)
		{
			if (s == false) s = inSpecial(pass[i]);
			if (l == false) s = inLower(pass[i]);
			if (b == false) s = inBiger(pass[i]);
			if (n == false) s = inNum(pass[i]);
		}
		return s&&l&&b&&n;
	}

	bool judge(string pass)
	{
		if (pass.length() < 8)
			return false;

		if (order2(pass) == false)
			return false;

	}

	float FunX(float  x)
	{
		float result = 0.0;
		if (x < -0.0 || x > 11.0)
			return result;
		float a = 0.0, b = 0.0;
		float value[5] = { 4, 12.9282, 23.4164, 35.1660, 54.7851 };
		float xpoint[5] = { 1, 3, 5, 7, 10 };
		int index = 0, i;
		if (x < 1)
		{
			a = (value[1] - value[0]) / (xpoint[1] - xpoint[0]);
			result = value[0] + a * (x - xpoint[0]);
		}
		else if (x >= 10)
		{
			a = (value[4] - value[3]) / (xpoint[4] - xpoint[3]);
			result = value[4] + a * (x - xpoint[4]);
		}
		else
		{
			for (i = 1; i < 5; i++)
			{
				if (x < xpoint[i] && x >= xpoint[i - 1])
				{
					index = i;
					break;
				}
			}
			a = (value[index] - value[index - 1]) / (xpoint[index] - xpoint[index - 1]);
			result = value[index] + a * (x - xpoint[index]);
		}
		return result;
	}
}


