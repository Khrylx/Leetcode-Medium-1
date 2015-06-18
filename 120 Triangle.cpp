#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) 
{
	for (int i = (int)triangle.size()-2; i >= 0; i--)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
		}
	}

	return triangle[0][0];
}

int main()
{

	return 1;
}