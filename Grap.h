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

	enum Graphkind { DG, DN, UDG, UDN }; //{有向图，无向图，有向网，无向网}
	enum Color {White, Gray, Black};
	
	struct Info
	{
		Color color;
		int   d;
		int   f;
		int   pi; //前驱
		Info() {color = White; d = 0; f = 0; pi = -1;};
	};

	struct Graph
	{
		vector<Info> vex;  //顶点数组
		int vexnum; //顶点个数
		int edge;   //图的边数
		vector<vector<int>> adjMatrix; //图的邻接矩阵
	};

	void createGrap(Graph& G);


};


