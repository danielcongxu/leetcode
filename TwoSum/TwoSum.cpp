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
		map<int, int>::iterator mapIter = mapValToIdx.find(target - nums[i]);
		if (mapIter != mapValToIdx.end() && i != mapIter->second)
		{
			return vector<int>{mapIter->second, i};
		}

		mapValToIdx.insert(pair<int, int>(nums[i], i));
	}
	return vector<int>();
}