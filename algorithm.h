#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include<algorithm>
/*****
C++ STL�㷨ϵ��
count(first,last,value); first���������׵�������last��������ĩ��������value��ѯ�ʵ�Ԫ�ء�
str.substr(f + 1); //��������ַ�������ʼλ�á��ַ����е�һ���ַ�������Ϊ 0,Ĭ��ֵΪ0.  ���Ƶ��ַ���Ŀ
*******/
using namespace std;

struct ELEMENT_STRU
{
	unsigned int uiElementLength;
	unsigned int uiElementValue;
};

const int maxV = 1000000;
void arrayInit(vector<vector<int>>& array, int num);
void arraydelete(int** &array, int n);
int dpf(int i, int j, int* &sum, vector<vector<int>>& dp);
int getLongSameStr(string str1, string str2);
int stone(vector<int> numlist, int start, int end);

bool compare(pair<string, int> a, pair<string, int> b);

void stortErrorInfo();
void cmpareCard();

int deleteNum(int num);
void lastWordLength();
bool isWordChar(char ch);

void findChar();
void mmRand();
void cutStrTo8();
void print8Char(string& str, int startPos, int len);

void findKey();
int findKeyInVector(vector<pair<int, int>> &table, int key, int num);
bool keyCompare(pair<int, int> a, pair<int, int> b);

void coutNumRe();

void reverseString();
string getLastWord(string& str, int lastIndex);

int minNumberInRotateArray(vector<int> rotateArray);

void Decode(unsigned int uiInputLength, unsigned char aInputByte[], unsigned int uiElementNum, ELEMENT_STRU astElement[]);
int nGetBitValue(char cByte, int nId);
void Decode1(unsigned int uiInputLength, unsigned char aInputByte[], unsigned int uiElementNum, ELEMENT_STRU astElement[]);

void finMinStep(int n);
bool findway(int s, int m, int n, int step);