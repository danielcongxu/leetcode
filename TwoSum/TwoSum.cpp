#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
	public:
		static vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	map<int, int> mapValToIdx;
	for (int i = 0; i < nums.size(); i++)
	{
		mapValToIdx.insert(pair<int, int>(nums[i], i));
	}

	for (int i = 0; i < nums.size(); i++)
	{
		map<int, int>::iterator mapIter = mapValToIdx.find(target - nums[i]);
		if (mapIter != mapValToIdx.end() && i != mapIter->second)
		{
			cout << "Find matched pair" << endl;
			cout << i << " " << mapIter->second << endl;
			return vector<int>{i, mapIter->second};
		}
	}
	cout << "None of matched pairs" << endl;
	return vector<int>();
}

void main()
{
	vector<int> temp = Solution::twoSum(vector<int>{2, 7, 11, 5}, 14);
}