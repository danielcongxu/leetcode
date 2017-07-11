#include <stack>
using namespace std;

class Solution {
public:
	static bool isValid(string s);
};

bool Solution::isValid(string s)
{
	stack<char> parentheses;
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		switch (*it)
		{
		case ')':
			if (parentheses.empty() || parentheses.top() != '(')
			{
				return false;
			}
			else
			{
				parentheses.pop();
				break;
			}
		case '}':
			if (parentheses.empty() || parentheses.top() != '{')
			{
				return false;
			}
			else
			{
				parentheses.pop();
				break;
			}
		case ']':
			if (parentheses.empty() || parentheses.top() != '[')
			{
				return false;
			}
			else
			{
				parentheses.pop();
				break;
			}
		default:
			parentheses.push(*it);
		}
	}
	return parentheses.size() == 0;
}