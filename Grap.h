#pragma once
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <xfunctional>
#include <istream>
#include <string>
#include <set>
#include <iterator>
#include<sstream>
#include <map>
#include <queue>
#include<set>
#include<list>
#include<stack>

namespace Graph
{
	using namespace std;

	enum Graphkind { DG, DN, UDG, UDN }; //{����ͼ������ͼ����������������}
	enum Color {White, Gray, Black};
	
	struct Info
	{
		Color color;
		int   d;
		int   f;
		int   pi; //ǰ��
		Info() {color = White; d = 0; f = 0; pi = -1;};
	};

	struct Graph
	{
		vector<Info> vex;  //��������
		int vexnum; //�������
		int edge;   //ͼ�ı���
		vector<vector<int>> adjMatrix; //ͼ���ڽӾ���
	};

	void createGrap(Graph& G);


};


