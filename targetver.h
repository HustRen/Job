#pragma once

// ���� SDKDDKVer.h ��������õ���߰汾�� Windows ƽ̨��

// ���ҪΪ��ǰ�� Windows ƽ̨����Ӧ�ó�������� WinSDKVer.h������
// �� _WIN32_WINNT ������ΪҪ֧�ֵ�ƽ̨��Ȼ���ٰ��� SDKDDKVer.h��

#include <SDKDDKVer.h>

/****
string��Ĳ��Һ�����
int find(char c, int pos = 0) const;//��pos��ʼ�����ַ�c�ڵ�ǰ�ַ�����λ��
int find(const char *s, int pos = 0) const;//��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
int find(const char *s, int pos, int n) const;//��pos��ʼ�����ַ���s��ǰn���ַ��ڵ�ǰ���е�λ��
int find(const string &s, int pos = 0) const;//��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
//���ҳɹ�ʱ��������λ�ã�ʧ�ܷ���string::npos��ֵ
int rfind(char c, int pos = npos) const;//��pos��ʼ�Ӻ���ǰ�����ַ�c�ڵ�ǰ���е�λ��
int rfind(const char *s, int pos = npos) const;
int rfind(const char *s, int pos, int n = npos) const;
int rfind(const string &s,int pos = npos) const;
//��pos��ʼ�Ӻ���ǰ�����ַ���s��ǰn���ַ���ɵ��ַ����ڵ�ǰ���е�λ�ã��ɹ���������λ�ã�ʧ��ʱ����string::npos��ֵ
int find_first_of(char c, int pos = 0) const;//��pos��ʼ�����ַ�c��һ�γ��ֵ�λ��
int find_first_of(const char *s, int pos = 0) const;
int find_first_of(const char *s, int pos, int n) const;
int find_first_of(const string &s,int pos = 0) const;
//��pos��ʼ���ҵ�ǰ���е�һ����s��ǰn���ַ���ɵ���������ַ���λ�á�����ʧ�ܷ���string::npos
int find_first_not_of(char c, int pos = 0) const;
int find_first_not_of(const char *s, int pos = 0) const;
int find_first_not_of(const char *s, int pos,int n) const;
int find_first_not_of(const string &s,int pos = 0) const;
//�ӵ�ǰ���в��ҵ�һ�����ڴ�s�е��ַ����ֵ�λ�ã�ʧ�ܷ���string::npos
int find_last_of(char c, int pos = npos) const;
int find_last_of(const char *s, int pos = npos) const;
int find_last_of(const char *s, int pos, int n = npos) const;
int find_last_of(const string &s,int pos = npos) const;
int find_last_not_of(char c, int pos = npos) const;
int find_last_not_of(const char *s, int pos = npos) const;
int find_last_not_of(const char *s, int pos, int n) const;
int find_last_not_of(const string &s,int pos = npos) const;
//find_last_of��find_last_not_of��find_first_of��find_first_not_of���ƣ�ֻ�����ǴӺ���ǰ����
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
if��n<2��return 0;                //С��2�������Ϸ�����nΪ���������������
for(int i = 2;i*i<=n2;i++)        //����n���Ӷ�
{
while(n2%i==0)
{
n2=n2/i;
cout << i ;
if(n2!=1)cout << "*";
}
}
if��n2��=1��    cout << n2;        //��nΪ����
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
size_t found = str.find_first_of(';');  //�ҵ���һ��';'��λ��
int start = 0;
found!=string::npos
string s1 = str.substr(start,found-start);
start = found+1;
found = str.find_first_of(';',found+1);


//�ַ���ת��Ϊ���� atoi
string str
stringstream ss;
ss<<str;
int x;
ss>>x;


getline()��ԭ�ͣ�
ͷ�ļ���#include <string>
istream& getline ( istream &is , string &str , char delim );
���У�istream &is ��ʾһ����������Ʃ��cin��
string&str��ʾ�Ѵ�������������ַ������������ַ����У������Լ����������strʲô�Ķ����ԣ���
char delim��ʾ��������ַ�ֹͣ���룬�ڲ����õ������ϵͳĬ�ϸ��ַ�Ϊ'\n'��Ҳ���ǻس����з��������س�ֹͣ���룩��

���ӣ�https://www.nowcoder.com/questionTerminal/de538edd6f7e4bc3a5689723a7435682
��Դ��ţ����

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

���ӣ�https://www.nowcoder.com/questionTerminal/2baa6aba39214d6ea91a2e03dff3fbeb
��Դ��ţ����

string getFileName(string path)
{
	int pos = path.rfind('\\');
	return path.substr(pos + 1);
}

std::find()
�÷���find(first, end, value);
��������[first��end���е�һ��ֵ����value��Ԫ��λ�ã���δ�ҵ�������end���������ص��ǵ�������ָ�룬��λ����Ϣ��
�ο�����main()������findvalue��ֵ
*/