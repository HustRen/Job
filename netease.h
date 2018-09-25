#pragma once

#include <algorithm>
#include <vector>

namespace netease
{
	using std::vector;
	using std::pair;

	bool compare(const pair<int, int> &a, const pair<int, int> &b);
	void mostMatchWork(vector<pair<int, int>> &workInfo, vector<int> &workers);
	int matchWork(vector<pair<int, int>> &workInfo, int worker);
	void mostMatchWorkTest();

	void pingduoduo();

	void findTeamMenber();
	int  findCore(int N, int X, int Y);
}
