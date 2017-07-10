#include <iostream>
#include <string>
#include <cmath>
#include <errno.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
	static int reverse(int x);
};

int Solution::reverse(int x)
{
	bool signSymbol = x > 0;
	string digits = to_string(abs(x));
	std::reverse(digits.begin(), digits.end());

	int result = atoi(((signSymbol ? "" : "-") + digits).c_str());

	if (errno == ERANGE)
	{
		return 0;
	}
	else
	{
		return result;
	}
}