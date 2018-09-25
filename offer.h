#pragma once
#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<math.h>
#include<assert.h>

namespace offer
{
	using namespace std;

	void printNum(char* num)
	{
		int i = 0;
		while (num[i] == '0')
			i++;
		if (num[i] != '\0')
			printf("%s\n", num + i);
	}

	void PrintNumRec(char* num, int len, int index)
	{
		if (index == len - 1)
		{
			printNum(num);
			return;
		}
		for (int i = 0; i < 10; i ++)
		{
			num[index + 1] = i + '0';
			PrintNumRec(num, len, index + 1);
		}

	}
	//打印1到长度为n的所有数字
	void PrintAllNum(int n)
	{
		if (n <= 0)
			return;
		char* num = new char[n + 1];
		num[n] = '\0';
		
		for (int i = 0; i < 10; i++)
		{
			num[0] = i + '0';
			PrintNumRec(num, n, 0);
		}
		delete[]num;
	}

	//合并链表
	struct ListNode
	{
		int val;
		ListNode *next;
	};
	ListNode* mergeList(ListNode* list1, ListNode* list2)
	{
		if (list1 == nullptr)
			return list2;
		if (list2 == nullptr)
			return list1;

		ListNode* pMerge = new ListNode;
		if (list1->val < list2->val)
		{
			pMerge = list1;
			pMerge->next = mergeList(list1->next, list2);
		}
		else
		{
			pMerge = list2;
			pMerge->next = mergeList(list1, list2->next);
		}
		return pMerge;
	}

	//判断序列是否是出栈序列
	bool isPopOrder(vector<int> &in, vector<int>& out)
	{
		bool result = false;
		if (!in.empty() &&  !out.empty())
		{
			stack<int> s;
			int i = 0, j = 0;
			
			while (j < out.size())
			{
				while (s.empty() || s.top() != out[j])
				{
					if (i == out.size())
						break;
					s.push(in[i ++]);
				}

				if (s.top() != out[j])
					break;

				s.pop();
				j++;
			}
			if (j == out.size() && s.empty())
			{
				result = true;
			}
		}
		return result;
	}
	
	//将一个数组组合成一个最小的数
	void PrintMinNum(vector<int> nums)
	{
		int n = nums.size();

		sort(nums.begin(), nums.end(), [](int a, int b) {
			string stra, strb; 
			stringstream sa,sb;
			sa << a; sa >> stra;
			sb << b; sb >> strb;
			return (stra + strb) < (strb + stra);
		});

		copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ""));
	}

	//把数字翻译成字符串
	int GetTranslationCount(string& str, int i)
	{
		if (i == str.length())
			return 0;
		if (i == str.length() - 1)
			return 1;

		int count = 0;
		count = GetTranslationCount(str, i + 1);

		string substr = str.substr(i, 2);
		if (substr >= "10" && substr <= "25")
			count += GetTranslationCount(str, i + 2);

		return count;
	}

	int GetTranslationCountUnrec(string& str)
	{
		int fp = 1, fpp = 1;
		int count = 0;
		for (int i = 1; i < str.length(); i ++)
		{
			string sub = str.substr(i - 1, 2);
			if (sub >= "10" && sub <= "25")
				count = fp + fpp;
			else
				count = fp;

			fpp = fp;
			fp = count;
		}
		return count;
	}

	//礼物的最大价值
	int getMaxValue_solution1(vector<vector<int>>& values, int rows, int cols)
	{
		vector<vector<int>> maxValues(rows + 1, vector<int>(cols + 1, 0));
		for (int row = 1; row <= rows; row++)
		{
			for (int col = 1; col <= cols; col++)
			{
				maxValues[row][col] = values[row - 1][col - 1] 
					+ max(maxValues[row - 1][col], maxValues[row][col - 1]);
			}
		}
		return maxValues[rows][cols];
	}

	int getMaxValue_solution2(vector<vector<int>>& values, int rows, int cols)
	{
		vector<int> maxValues(cols + 1, 0);
		for (int row = 1; row <= rows; row++)
		{
			for (int col = 1; col <= cols; col++)
			{
				maxValues[col] = values[row - 1][col - 1]
					+ max(maxValues[col], maxValues[col - 1]);
			}
		}
		return maxValues[cols];
	}

	//最长不含重复字符的子串
	int longgestSubStringWithoutDuplication(string& str)
	{
		int maxi = 0, max = 0;
		vector<int> charHash(256, -1);
		for (int i = 0; i < str.length(); i++)
		{
			if (i - charHash[str[i]] > maxi)
				maxi ++;
			else
				maxi = i - charHash[str[i]];

			charHash[str[i]] = i;
			if (maxi > max)
				max = maxi;
		}
		return max;
	}

	//不用加减乘除做加法
	int Add(int a, int b)
	{
		int sum, carry;
		do
		{
			sum = a^b;
			carry = (a&b) << 1;
			a = sum;
			b = carry;

		} while (b != 0);
		return a;
	}

	//优化过后的next数组求法
	vector<int> getNext(string p) 
	{
		vector<int> next(p.length());
		next[0] = -1;
		int j = 0;
		int k = -1;
		while (j < p.length() - 1)
		{
			//p[k]表示前缀，p[j]表示后缀
			if (k == -1 || p[j] == p[k])
			{
				//较之前next数组求法，改动在下面4行
				if (p[++j] == p[++k]) 
				{
					next[j] = next[k];// 当两个字符相等时要跳过
				}
				else
				{
					next[j] = k;//之前只有这一行
				}
		    }
			else 
			{
				k = next[k];
			}
		}
		return next;
	}

	//KMP算法
	int KMP(string s, string p)
	{
		int i = 0, j = 0;
		int sLen = s.length(), plen = p.length();
		vector<int> next = getNext(p);
		while (i < sLen)
		{
			if (j == -1 || s[i] == p[j])
			{
				i++;
				j++;
			}
			else
				j = next[j];
			if (j == plen)
				break;
		}
		return j == plen ? i - plen : -1;
	}

	void Memerycopy(void* scr, void* dest, int len)
	{
		assert(scr != NULL && dest != NULL);
		if (dest == scr)
			return;
		char* ps = (char*)scr;
		char* pd = (char*)dest;
		if (pd < ps)
		{
			while (len--)
			{
				*pd = *ps;
				pd++; ps++;
			}
		}
		else
		{
			pd = pd + len;
			ps = ps + len;
			while (len--)
			{
				*(--pd) = *(--ps);
			}
		}
	}

	void test()
	{
		//PrintAllNum(1);
		vector<int> a = { 1,2,3,4,5 };
		vector<int> b = { 4,5,3,2,1 };
		vector<int> c = { 3, 32, 321 };

		/*cout << isPopOrder(a, b);
		cout << isPopOrder(a, c);*/
		//PrintMinNum(c);
		string str = "12258";
		string str1 = "arabcacfr";
		cout << GetTranslationCount(str, 0) << endl;
		cout << GetTranslationCountUnrec(str) << endl;
		cout << longgestSubStringWithoutDuplication(str1) << endl;

		string strA = "aabcbcbf";
		string strB = "bc";
		cout << KMP(strA, strB);
	}
}
