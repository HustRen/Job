#pragma once

// 包括 SDKDDKVer.h 将定义可用的最高版本的 Windows 平台。

// 如果要为以前的 Windows 平台生成应用程序，请包括 WinSDKVer.h，并将
// 将 _WIN32_WINNT 宏设置为要支持的平台，然后再包括 SDKDDKVer.h。

#include <SDKDDKVer.h>

/****
string类的查找函数：
int find(char c, int pos = 0) const;//从pos开始查找字符c在当前字符串的位置
int find(const char *s, int pos = 0) const;//从pos开始查找字符串s在当前串中的位置
int find(const char *s, int pos, int n) const;//从pos开始查找字符串s中前n个字符在当前串中的位置
int find(const string &s, int pos = 0) const;//从pos开始查找字符串s在当前串中的位置
//查找成功时返回所在位置，失败返回string::npos的值
int rfind(char c, int pos = npos) const;//从pos开始从后向前查找字符c在当前串中的位置
int rfind(const char *s, int pos = npos) const;
int rfind(const char *s, int pos, int n = npos) const;
int rfind(const string &s,int pos = npos) const;
//从pos开始从后向前查找字符串s中前n个字符组成的字符串在当前串中的位置，成功返回所在位置，失败时返回string::npos的值
int find_first_of(char c, int pos = 0) const;//从pos开始查找字符c第一次出现的位置
int find_first_of(const char *s, int pos = 0) const;
int find_first_of(const char *s, int pos, int n) const;
int find_first_of(const string &s,int pos = 0) const;
//从pos开始查找当前串中第一个在s的前n个字符组成的数组里的字符的位置。查找失败返回string::npos
int find_first_not_of(char c, int pos = 0) const;
int find_first_not_of(const char *s, int pos = 0) const;
int find_first_not_of(const char *s, int pos,int n) const;
int find_first_not_of(const string &s,int pos = 0) const;
//从当前串中查找第一个不在串s中的字符出现的位置，失败返回string::npos
int find_last_of(char c, int pos = npos) const;
int find_last_of(const char *s, int pos = npos) const;
int find_last_of(const char *s, int pos, int n = npos) const;
int find_last_of(const string &s,int pos = npos) const;
int find_last_not_of(char c, int pos = npos) const;
int find_last_not_of(const char *s, int pos = npos) const;
int find_last_not_of(const char *s, int pos, int n) const;
int find_last_not_of(const string &s,int pos = npos) const;
//find_last_of和find_last_not_of与find_first_of和find_first_not_of相似，只不过是从后向前查找
**/

/****
#include <stdio.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
int Sudoku[9][9] = { 0 };
bool solve(int num);
bool check(int line, int row, int val);
int main()
{
	FOR(i, 0, 9) FOR(j, 0, 9) scanf("%d", &Sudoku[i][j]);
	solve(0);
	FOR(i, 0, 9) FOR(j, 0, 9)
		j == 8 ? printf("%d\n", Sudoku[i][j]) : printf("%d ", Sudoku[i][j]);
	return 0;
}

bool solve(int num)
{
	int line = num / 9;
	int row = num % 9;
	if (num == 81)
		return true;
	else if (Sudoku[line][row] != 0)
		return solve(num + 1);
	else
	{
		FOR(val, 1, 10)
		{
			if (check(line,row,val))
			{
				Sudoku[line][row] = val;
				if (solve(num + 1))
					return true;
				Sudoku[line][row] = 0;
			}
		}
	}
	return false;
}

bool check(int line, int row, int val)
{
	FOR(i, 0, 9)
	if (Sudoku[i][row] == val)
		return false;
	FOR(j, 0, 9)
		if (Sudoku[line][j] == val)
			return false;
	FOR(i, line / 3 * 3, (line/3+1)*3)
		FOR(j, row / 3 * 3, (row/3+1)*3)
			if (Sudoku[i][j] == val)
				return false;
	return true;
}
*/

/*
#include <iostream>
using namespace std;
int main()
{
int n, n2;
cin >> n;
cout << n << "=";
n2 = n;
if（n<2）return 0;                //小于2的数不合法，若n为质数则输出它本身
for(int i = 2;i*i<=n2;i++)        //根号n复杂度
{
while(n2%i==0)
{
n2=n2/i;
cout << i ;
if(n2!=1)cout << "*";
}
}
if（n2！=1）    cout << n2;        //当n为质数
return 0;
}
*/

/*
int main()
{
string str;
while(getline(cin, str))
{
int count = 0;
int len = str.length();
int charCount[128] = {0};
for(int i = 0; i < len; i++)
{
if(str[i] >= 0 && str[i] <= 127)
{
charCount[str[i]] ++;
}
}
for(int i = 0; i < 128; i++)
{
if(charCount[i] != 0)
{
count ++;
}
}
cout << count << endl;
}
}*/

/*
size_t found = str.find_first_of(';');  //找到第一个';'的位置
int start = 0;
found!=string::npos
string s1 = str.substr(start,found-start);
start = found+1;
found = str.find_first_of(';',found+1);


//字符串转换为数据 atoi
string str
stringstream ss;
ss<<str;
int x;
ss>>x;


getline()的原型：
头文件：#include <string>
istream& getline ( istream &is , string &str , char delim );
其中，istream &is 表示一个输入流，譬如cin；
string&str表示把从输入流读入的字符串存放在这个字符串中（可以自己随便命名，str什么的都可以）；
char delim表示遇到这个字符停止读入，在不设置的情况下系统默认该字符为'\n'，也就是回车换行符（遇到回车停止读入）。

链接：https://www.nowcoder.com/questionTerminal/de538edd6f7e4bc3a5689723a7435682
来源：牛客网

vector<string> split(string str, char del)
{
	stringstream ss(str);
	string tok;
	vector<string> ret;
	while(getline(ss, tok, del))
	{
		ret.push_back(tok);
	}
	return ret;
}

链接：https://www.nowcoder.com/questionTerminal/2baa6aba39214d6ea91a2e03dff3fbeb
来源：牛客网

string getFileName(string path)
{
	int pos = path.rfind('\\');
	return path.substr(pos + 1);
}

std::find()
用法：find(first, end, value);
返回区间[first，end）中第一个值等于value的元素位置；若未找到，返回end。函数返回的是迭代器或指针，即位置信息。
参考代码main()，查找findvalue的值
*/