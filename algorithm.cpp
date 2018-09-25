#include "stdafx.h"
#include "algorithm.h"


bool compare(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

void stortErrorInfo()
{
	string input, file;
	vector<pair<string, int>> errors;
	while (getline(cin, input))
	{
		if (input.size() == 0)
			break;
		unsigned int f = input.rfind('\\');
		file = input.substr(f + 1); //所需的子字符串的起始位置。字符串中第一个字符的索引为 0,默认值为0.  复制的字符数目
		errors.push_back(make_pair(file, 1));
		for (int i = 0; i<(errors.size() - 1); i++)
		{
			if (errors[i].first == file)
			{
				errors[i].second++;
				errors.pop_back(); break;
			}
		}
	}
	stable_sort(errors.begin(), errors.end(), compare);
	int idx = 0;
	while (idx<8 && idx<errors.size())
	{
		string check = errors[idx].first;
		int t = check.find(' ');
		if (t>16)
			errors[idx].first.erase(0, t - 16);
		cout << errors[idx].first << ' ' << errors[idx].second << endl;
		idx++;
	}
}

void cmpareCard()
{
	string line;
	while (getline(cin, line))
	{
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else 
		{
			int dash = line.find('-');
			string car1 = line.substr(0, dash);
			string car2 = line.substr(dash + 1);
			int c1 = count(car1.begin(), car1.end(), ' ');
			int c2 = count(car2.begin(), car2.end(), ' ');
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2) 
			{
				if (str.find(first1)>str.find(first2))
					cout << car1 << endl;
				else
					cout << car2 << endl;
			}
			else
				if (c1 == 3)
					cout << car1 << endl;
				else if (c2 == 3)
					cout << car2 << endl;
				else
					cout << "ERROR" << endl;
		}
	}
}

int deleteNum(int num)
{
	if (num > 1000)
		num = 1000;
	
	int* a = new int[num];
	for (int i = 0; i < num; i++) 
		a[i] = i;
	int taotal = num;
	int index = 2;
	while (num > 0)
	{
		if (a[index] != -1)
		{
			a[index] = -1;
			num--;

			for (int i = 0; i < 2; i++)
			{
				while (a[index] == -1)
				{
					index ++;
					index = index % taotal;
				}
			}
		}
		
	}
	delete []a;
	return index;
}

void lastWordLength()
{
	std::string str;
	while (getline(cin, str))
	{
		int len = str.length();
		int lastLen = 0;
		if (isWordChar(str[len - 1]))
		{
			lastLen = str.rfind(' ');
			lastLen = len - lastLen - 1;
		}
		else
		{
			int index = len - 2;
			while (index >= 0 && !isWordChar(str[index]))
			{
				index--;
			}
			while (str[index] != ' ')
			{
				index--;
				lastLen ++;
			}
		}

		std::cout << lastLen;
	}
}

bool isWordChar(char ch)
{
	bool flage = false;
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		flage = true;

	return flage;
}

void findChar()
{
	string str;
	while (getline(cin, str))
	{
		char ch;
		string dest;
		cin >> ch;
		if (ch >= 'A' && ch <= 'Z')
			ch = ch - 'A' + 'a';
		transform(str.begin(), str.end(), dest.begin(), ::tolower);
		int len = str.length();
		int count = 0;
		for (int i = 0; i < len; i++)
		{
			if (dest[i] == ch)
				count++;
		}
		cout << count;
	}
}

void mmRand()
{
	int n = 0;
	while (cin >> n)
	{
		int* array = new int[1001]();

		for (int i = 0; i < n; i++)
		{
			int index = -1;
			cin >> index;
			array[index] ++;
		}

		for (int i = 1; i <= 1000; i++)
		{
			if (array[i] > 0)
				cout << i << endl;
		}
	}
}

void cutStrTo8()
{
	string str;
	while (getline(cin, str))
	{
		int len = str.length();
		int startPos = 0;
		while (startPos < len)
		{
			print8Char(str, startPos, len);
			startPos += 8;
		}
	}
}

void print8Char(string& str, int startPos, int len)
{
	if (startPos + 8 <= len)
	{
		for (int i = 0; i < 8; i++)
		{
			cout << str[startPos + i];
		}
	}
	else
	{
		for (int i = startPos; i < len; i++)
		{
			cout << str[i];
		}
		for (int i = len - startPos; i < 8; i++)
		{
			cout << 0;
		}
	}
	cout << endl;
}

void findKey()
{
	vector<pair<int, int>> table;
	pair<int, int> temp;
	int N = 0, num = 0;
	while (cin >> N)
	{
		table.resize(N);
		for (int i = 0; i < N; i++)
		{
			cin >> temp.first >> temp.second;
			int index = findKeyInVector(table, temp.first, num);
			if (index == num)
			{
				table[num] = temp;
				num++;
			}
			else
			{
				table[index].second += temp.second;
			}
		}
		stable_sort(table.begin(), table.begin() + num, keyCompare);
		for (int i = 0; i < num; i++)
		{
			cout << table[i].first <<  " "<< table[i].second << endl;
		}
	}
}

int findKeyInVector(vector<pair<int, int>> &table, int key, int num)
{
	int index = num;
	for (int i = 0; i < num; i++)
	{
		pair<int, int> temp = table[i];
		if (key == temp.first)
		{
			index = i;
			break;
		}
	}
	return index;
}

bool keyCompare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

void coutNumRe()
{
	int num = 0;
	while (cin >> num)
	{
		int a[10] = {0};
		while (num)
		{
			int index = num % 10;
			num = num / 10;
			if (a[index] == 0)
			{
				cout << index;
			}
			a[index] ++;
		}
		cout << endl;
	}
}

void reverseString()
{
	string str;
	while (getline(cin, str))
	{
		int len = str.length() - 1;
		while (len >= 0)
		{
			vector<char> word;
			while (len >= 0 && str[len] != ' ')
			{
				word.push_back(str[len]);
				len --;
			}

			for (int i = word.size() - 1; i >= 0; i--)
			{
				cout << word[i];
			}
			if (len > 0)
			{
				cout << ' ';
			}
			len--;
		}
		cout << endl;
	}
}

string getLastWord(string& str, int lastIndex)
{
	string word;
	int spaceIndex = str.rfind(' ', lastIndex);
	if (spaceIndex == lastIndex)
	{
		word = str.substr(0, lastIndex);
	}
	else
	{
		word = str.substr(spaceIndex + 1, lastIndex - spaceIndex);
		word = word + " ";
	}
	
	return word;
}

int minNumberInRotateArray(vector<int> rotateArray)
{
	int len = rotateArray.size();
	if (len == 0)
	{
		return 0;
	}
	int start = 0, end = len - 1;
	
	while (end - start > 1)
	{
		int mid = (start + end) / 2;
		if (rotateArray[start] == rotateArray[end])
		{
			int min = rotateArray[start];
			for (int i = start + 1; i < end; i++)
			{
				if (min > rotateArray[i])
					min = rotateArray[i];
			}
			return min;
		}
		if (rotateArray[mid] >= rotateArray[start])
		{
			start = mid;
		}
		else
		{
			end = mid;
		}
	}
	return rotateArray[end];
}

void arrayInit(vector<vector<int>>& array, int num)
{
	for (int j = 0; j < num; j++)
	{
		vector<int> temp;
		temp.resize(num);
		for (int i = 0; i < num; i++)
		{
			temp[i] = maxV;
		}
		array.push_back(temp);
	}
}

void arraydelete(int** &array, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[]array[i];
	}
	delete[]array;
	array = nullptr;
}

int dpf(int i, int j, int* &sum, vector<vector<int>>& dp)
{
	if (dp[i][j] == maxV)
	{
		for (int k = i; k < j; k++)
		{
			if (dp[i][j] > dpf(i, k, sum, dp) + dpf(k + 1, j, sum, dp) + sum[j] - sum[i - 1])
			{
				dp[i][j] = dpf(i, k, sum, dp) + dpf(k + 1, j, sum, dp) + sum[j] - sum[i - 1];
			}
		}
	}
	return dp[i][j];
}

int getLongSameStr(string str1, string str2)
{
	//string subStr = "";
	//int begin = 0;
	//int end = 1;
	//int maxLength = 0;
	//string targetStr = "";
	//vector<string> targetArr;
	//while (true)
	//{
	//	str1.length
	//	//subStr = str2.substr(begin, end);
	//	if (str1.find(subStr) != -1)
	//	{
	//		end++;
	//		targetArr.push_back(subStr);
	//	}
	//	else
	//	{
	//		begin++;
	//		end = 1;
	//	}
	//	if (begin + end == str2.length())
	//	{
	//		break;
	//	}
	//}
	//for (int i = 0; i < targetArr.size(); i++)
	//{
	//	if (targetArr[i].length() > maxLength)
	//	{
	//		maxLength = targetArr[i].length();
	//	}
	//}
	return 0;
}

int stone(vector<int> numlist, int start, int end)
{
	int size = end - start + 1;
	if (size <= 0) return 0;
	if (size == 1) return numlist[start];
	if (size == 2) return numlist[start] + numlist[end];

	int min = 9999999;
	for (int k = start + 1; k < end; k++)
	{
		if ((stone(numlist, start, k) + stone(numlist, k + 1, end)) < min)
			min = stone(numlist, start, k) + stone(numlist, k + 1, end);
	}
	return min;
}

void Decode(unsigned int uiInputLength, unsigned char aInputByte[], unsigned int uiElementNum, ELEMENT_STRU astElement[])
{
	if (!aInputByte || !astElement)
		return;
	if (uiElementNum == 0 || uiInputLength == 0)
		return;
	/*其实可以存储成char,为了计算方便,
	不考虑存储空间大小*/
	vector<int> vec;

	unsigned int i = 0;
	unsigned int temp = 0;
	int temp1 = 0x80;
	unsigned int j = 0, k = 0;
	int sum = 0;

	int bittemp = 0;
	/*将数据转成2进制数据存入int 数组中*/
	for (i = 0; i<uiInputLength; i++) {
		temp = aInputByte[i];
		for (j = 0; j<8; j++) {
			//只要获取当前最高位和0x1000 0000 的与值
			bittemp = (temp&temp1);
			//0x1000 0000 或者0x0000 0000 右移动7位得到1或者0;
			bittemp = (bittemp >> 7);
			/*当前数左移动1位*/
			vec.push_back(bittemp);
			temp = (temp << 1);
		}
	}
	/*解析数值个数*/
	int size = vec.size();
	for (i = 0; i<uiElementNum; i++) {
		temp = 0;
		for (j = 0; j<astElement[i].uiElementLength; j++) {
			if (astElement[i].uiElementLength<1 && \
				astElement[i].uiElementLength>31)
				return;
			/*解析数值的总长度uiElementLength之和
			大于vec的总长度，这里做截取处理*/
			if (k>size) {
				break;
			}
			temp = (temp << 1) + vec[k];
			k++;

		}
		if (k>size&&temp != 0) {
			astElement[i].uiElementValue = temp;
			break;
		}
		else if (k>size&&temp == 0) {
			break;
		}
		astElement[i].uiElementValue = temp;
	}

	return;
}

/*
功能:获取一个字节某一位的数字
输入:
cByte，输入字节
nId，从右往左数的id号，从零开始
返回值:
返回该位上的数字，取值为0或1
*/
int nGetBitValue(char cByte, int nId)
{
	int nTem = 1 << (8 - nId - 1);
	return ((nTem & cByte) > 0) ? 1 : 0;
}

void Decode1(unsigned int uiIutputLen, unsigned char aInputByte[], unsigned int uiElementNum, ELEMENT_STRU astElement[])
{
	/*在这里实现功能*/
	if ((0 == uiIutputLen) || (NULL == aInputByte) || (0 == uiElementNum) || (NULL == astElement))
		return;
	int i = 0;
	int nStartBit = 0;
	int nLen = 0;
	for (i = 0; i < uiElementNum; i++)
	{
		int nTem = 0;
		nLen = astElement[i].uiElementLength;
		for (int j = 0; j < nLen; j++)
		{
			int nWordLable, nId, nCurBit;
			nCurBit = nStartBit + j;
			nWordLable = nCurBit / 8;
			nId = nCurBit % 8;

			int nBit = nGetBitValue(aInputByte[nWordLable], nId);
			nTem = (nTem << 1) + nBit;
		}
		astElement[i].uiElementValue = nTem;
		nStartBit += nLen;
	}
	return;
}

void finMinStep(int n)
{
	int step = 0;
	findway(1, 1, n, step);
}

bool findway(int s, int m, int n, int step)
{
	if (s > n)
	{ 
		return false;
	}
	if (s == n)
	{
		cout << step;
		return true;
	}
	
	bool ans = findway(s + s, s, n, step + 1);
	if(ans == false)
		ans = findway(s + m, m, n, step + 1);	
		
	return ans;
}


