#include "stdafx.h"
#include "tencent.h"


namespace tencent
{

//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
	using namespace std;

	int helper(string s)
	{
		string rev = s;
		reverse(rev.begin(), rev.end());
		int size = s.size();
		vector<vector<int>> c(size + 1, vector<int>(size + 1));
		for (int i = 1; i <= size; ++i)
		{
			for (int j = 1; j <= size; ++j)
			{
				if (s[i - 1] == rev[j - 1])
				{
					c[i][j] = c[i - 1][j - 1] + 1;
				}
				else if (c[i - 1][j] >= c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
				}
				else if (c[i - 1][j] < c[i][j - 1])
				{
					c[i][j] = c[i][j - 1];
				}
			}
		}
		int count = 0;
		for(int i = 1; i <=size; i++)
		{
			for (int j = i; j <= size; j++)
			{
				if (c[i][j] > 0)
				{
					count++;
				}
			}
		}
		return count - 1;
	}
	void test()
	{
		string s;
		while (cin >> s)
			cout << helper(s) << endl;
	}

	int help(string str) 
	{
		int size = str.length();
		vector<vector<int> > c(size, vector<int>(size));

		for (int j = 0; j < size; j++)
		{
			c[j][j] = 1;
			for (int i = j - 1; i >= 0; i--)
			{
				c[i][j] = c[i + 1][j] + c[i][j - 1] - c[i + 1][j - 1];
				if (str[i] == str[j])
					c[i][j] += 1 + c[i + 1][j - 1];
			}
		}
		return c[0][size - 1];
	}

	int oneQ()
	{
		int time;
		unsigned long long n, x, j;
		while (cin >> time)
		{
			vector <unsigned long long> N;
			for (int i = 0; i < time; i++)
			{
				cin >> n;
				N.push_back(n);
			}
			for (int i = 0; i < time; i++)
			{
				n = N[i];
				if (n % 2 == 1)
					cout << "No" << endl;
				else
				{
					for (j = 2; j <= n; j = j + 2)
					{
						x = n / j;
						if (x % 2 == 1 && x*j == n)
						{
							cout << x << " " << j << endl;
							break;
						}
					}
					if (j > n)
						cout << "No" << endl;
				}
			}
		}
		return 0;
	}
    
	int horse()
	{
		int K;
		int x, y;
		cin >> K;
		cin >> x >> y;
		int ***index;
		index = new int**[8];
		for (int i = 0; i < 9; i++)
		{
			index[i] = new int*[8];
			for (int j = 0; j < 9; j++)
			{
				index[i][j] = new int[K];
			}
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				for (int k = 0; k < K; k++)
				{
					index[i][j][k] = 0;
				}
			}
		}
		if (K == 0)
		{
			return 0;
		}
		if (K > 0)
		{
			index[1][2][0] = 1;
			index[2][1][0] = 1;
		}
		for (int k = 1; k < K; k++)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (i + 2 >= 0 && i + 2 <= 8 && j + 1 >= 0 && j + 1 <= 8)
					{
						index[i][j][k] += index[i + 2][j + 1][k - 1];
					}
					if (i - 2 >= 0 && i - 2 <= 8 && j + 1 >= 0 && j + 1 <= 8)
					{
						index[i][j][k] += index[i - 2][j + 1][k - 1];
					}
					if (i + 2 >= 0 && i + 2 <= 8 && j - 1 >= 0 && j - 1 <= 8)
					{
						index[i][j][k] += index[i + 2][j - 1][k - 1];
					}
					if (i - 2 >= 0 && i - 2 <= 8 && j - 1 >= 0 && j - 1 <= 8)
					{
						index[i][j][k] += index[i - 2][j - 1][k - 1];
					}
					if (i + 1 >= 0 && i + 1 <= 8 && j + 2 >= 0 && j + 2 <= 8)
					{
						index[i][j][k] += index[i + 1][j + 2][k - 1];
					}
					if (i - 1 >= 0 && i - 1 <= 8 && j + 2 >= 0 && j + 2 <= 8)
					{
						index[i][j][k] += index[i - 1][j + 2][k - 1];
					}
					if (i + 1 >= 0 && i + 1 <= 8 && j - 2 >= 0 && j - 2 <= 8)
					{
						index[i][j][k] += index[i + 1][j - 2][k - 1];
					}
					if (i - 1 >= 0 && i - 1 <= 8 && j - 2 >= 0 && j - 2 <= 8)
					{
						index[i][j][k] += index[i - 1][j - 2][k - 1];
					}
					index[i][j][k] = index[i][j][k] % 1000000007;
				}
			}
		}
		cout << index[x][y][K - 1];
	}

	void setStudy()
	{
		set<string> a, b, inter, unio, diff;
		a.insert("hello");
		a.insert("world");
		b.insert("hello");
		b.insert("china");
		set<string>::iterator i;
		cout << "遍历集合：" << endl;
		for (i = a.begin(); i != a.end(); i++)
		{
			cout << *i << "	";
		}
		cout << endl << "集合求交：" << endl;
		/*set_intersection(a.begin(), a.end(), b.begin(), b.end(), inter.begin());
		for (i = inter.begin(); i != inter.end(); i++)
		{
			cout << *i << "	";
		}
		cout << endl << "集合求并：" << endl;
		set_union(a.begin(), a.end(), b.begin(), b.end(), unio.begin());
		for (i = unio.begin(); i != unio.end(); i++)
		{
			cout << *i << "	";
		}
		cout << endl << "集合求差：" << endl;
		set_difference(a.begin(), a.end(), b.begin(), b.end(), diff.begin());
		for (i = diff.begin(); i != diff.end(); i++)
		{
			cout << *i << "	";
		}*/
	}

	void mapStudy()
	{
		map<string, string> dir;
		dir.insert(pair<string, string>("INT", "int*"));
		dir.insert(pair<string, string>("INTP", "INT*"));
		vector<string> per;
		string test = "INTP";
		while (dir.count(test)) // dir.count(test) != dir.end();
		{
			test = dir.find(test)->second;
			int n = test.find_first_of("*");
			if (n > 0)
			{
				per.push_back(test.substr(n));
				test = test.substr(0, n);
			}
				
		}
		cout << test;
		for (vector<string>::iterator i = per.begin(); i != per.end(); i++)
		{
			cout << *i;
		}
	}

	void listStudy()
	{
		list<int> l(5);
		int a[5] = {0,1,1,2,3};
		l.assign(a, a + 5);
		for (auto itr = l.begin(); itr != l.end(); itr ++)
		{
			cout << *itr << " ";
		}
		cout << endl;
		l.insert(l.begin(), 3);
		l.push_back(5);
		l.push_front(-1);
		for (auto itr = l.begin(); itr != l.end(); itr++)
		{
			cout << *itr << " ";
		}
		cout << endl;
		l.unique();
		for (auto itr = l.begin(); itr != l.end(); itr++)
		{
			cout << *itr << " ";
		}
		cout << endl;
		l.reverse();
		for (auto itr = l.begin(); itr != l.end(); itr++)
		{
			cout << *itr << " ";
		}
		cout << endl;

		l.sort(less<>());//l.sort(greater<int>());
		for (auto itr = l.begin(); itr != l.end(); itr++)
		{
			cout << *itr << " ";
		}
		cout << endl;
	}

	void lineInput()
	{
		string sLine;
		int n, id;
		cin >> n >> id;
		getline(cin, sLine);
		vector <vector<int>> connect;
		for (int i = 0; i < n; i++)
		{
			getline(cin, sLine);
			istringstream is(sLine);
			int a;
			vector<int> nums;
			while (is >> a)
			{
				nums.push_back(a);
			}
			connect.push_back(nums);
		}
	}

	void stlAlgoStudy()
	{
		int a[5] = {0, 1, 2, 3, 4};
		int b[4] = {1, 3, 4, 5};
		int c[5] = {8, 1, 4, 2, 6};
		cout << binary_search(a, a + 5, 3) << endl; //二分查找,需要原序列有序，返回值为bool
		cout << find(a, a + 5, 3) -  a << endl;   //循序查找，返回值为该值得迭代器
		cout << includes(a, a + 5, b, b + 3) << endl; //序列a中是否包含b
		set_union(a, a + 5, b, b + 3, ostream_iterator<int>(cout, " ")); //求两个集合的交集
		cout << endl;
		sort(c, c + 5, [](int a, int b) {return a < b; });
		for_each(c, c + 5, [](int n) {cout << n << " "; });
		cout << endl;
		make_heap(c, c + 5, [](int a, int b) {return a < b; });
		for_each(c, c + 5, [](int n) {cout << n << " "; });
		cout << endl;
		sort_heap(c, c + 5);
		for_each(c, c + 5, [](int n) {cout << n << " "; });
		cout << endl;

		copy(a, a + 5, ostream_iterator<int>(cout, " "));
		cout << endl;

		string iniString = "abcde";
		int start = 0, end = iniString.length() - 1;
		while (start < end)
		{
			swap(iniString[start++], iniString[end--]);
		}
		cout << iniString;
	}

	void decompression(string zipStr)
	{
		struct StrInfo
		{
			string str;
			int    num;
		};

		auto isNum = [](char c){if (c >= '0' && c <= '9') return true; else return false;};
		vector<StrInfo> ans;
		int last = 0, current = 0; 
		int len = zipStr.length();
		while (current < len)
		{
			if (isNum(zipStr[current]))
			{
				int i = 1;
				while (isNum(zipStr[current + i])) i++;
				
				StrInfo temp;
				temp.str = zipStr.substr(last, current - last);
				string numStr = zipStr.substr(current, i);
				temp.num = atoi(numStr.c_str());

				current = current + i;
				last = current;
				ans.push_back(temp);
			}
			else
			{
				current++;
			}
		}

		sort(ans.begin(), ans.end(), [](StrInfo a, StrInfo b) {return a.num < b.num; });
		
		int wordnum = ans.size();
		int i = 0;
		while (i < wordnum)
		{
			vector<StrInfo> tempa;
			int j = 0;
			while (ans[i].num == ans[i + j].num)
			{
				tempa.push_back(ans[i + j]);
				j++;
				if (i + j >= wordnum) break;
			}

			sort(tempa.begin(), tempa.end(), [](StrInfo a, StrInfo b) {
				if (a.str.length() != b.str.length()) return a.str.length() < b.str.length();
				else	return a.str < b.str; 
			});
			i = i + j;
			for_each(tempa.begin(), tempa.end(), [](StrInfo a) {while (a.num--) cout << a.str; });
		}
		cout << endl;
	}
}
