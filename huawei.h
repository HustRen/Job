#pragma once
#include<iostream>
#include<vector>
#include<string>

namespace huawei
{
	using namespace std;
	string LargeNumAdd(string a, string b)
	{
		string big = a, small = b;
		if (big.length() < small.length())
			swap(big, small);
		big = '0' + big;
		string zero(big.length() - small.length(), '0');
		small = zero + small;
		int len = small.length();
		int over = 0, ans = 0;
		auto num = [](char c) {return int(c - '0'); };
		for (int i = len - 1; i >= 0; i--)
		{
			ans = num(small[i]) + num(big[i]) + over;
			over = ans / 10;
			ans = ans % 10;
			big[i] = ans + '0';
		}
		if (big[0] == '0')
			return big.substr(1, big.length() - 1);
		return big;
	}

	string LargeNumMulti(const string& astr, char bchar)
	{
		int len = astr.length();
		int over = 0, b = bchar - '0';
		string str(len + 1, '0');
		auto num = [](char c) {return int(c - '0'); };
		for (int i = len - 1; i >= 0; i--)
		{
			int ans = num(astr[i]) * b + over;
			over = ans / 10;
			ans = ans % 10;
			str[i + 1] = ans + '0';
		}
		if (str[0] == '0')
			return str.substr(1, len);
		return str;
	}

	string LargeNumMulti(string a, string b)
	{
		if (a.length() < b.length())
			swap(a, b);
		int blen = a.length();
		int slen = b.length();
		vector<string> ansT;
		for (int i = slen - 1; i >= 0; i--)
		{
			if (b[i] != '0')
			{
				string zero(slen - 1 - i, '0');
				ansT.push_back(LargeNumMulti(a, b[i]) + zero);
			}
		}
		int len = ansT.size();
		string ans;
		for (int i = 0; i < len; i++)
		{
			ans = LargeNumAdd(ans, ansT[i]);
		}
		return ans;
	}

	void test()
	{
		string a, b;
		cin >> a >> b;
		a = "200000000000000000000";
		b = "300000000000000000000";
		cout << LargeNumMulti(a, b);
	}
}