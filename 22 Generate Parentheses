#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void generateParenthesisHelper(vector<string>& solution,int lNum,int rNum,string& s,stack<char>& S)
{
	if (lNum == 0 && rNum==0)
	{
		solution.push_back(s);
	}

	if (lNum > 0)
	{
		S.push('(');
		s.push_back('(');
		generateParenthesisHelper(solution,lNum-1,rNum,s,S);
		s.pop_back();
		S.pop();
	}

	if (rNum > 0 && !S.empty() && S.top()=='(')
	{
		S.pop();
		s.push_back(')');
		generateParenthesisHelper(solution,lNum,rNum-1,s,S);
		s.pop_back();
		S.push('(');
	}
}

vector<string> generateParenthesis(int n) 
{
	vector<string> solution;
	stack<char> S;
	string s;
	int lNum = n;
	int rNum = n;

	generateParenthesisHelper(solution,lNum,rNum,s,S);

	return solution;
}


int main()
{
	
	vector<string> sol = generateParenthesis(3);

	return 1;
}