#include <iostream>
#include <vector>
using namespace std;


// Accepted on O(n)
int getMaxSumOfSubSeq(vector<int>& arr)
{
	int arrSum = 0;
	int maxArrSum = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		arrSum += arr[i];
		if (arrSum < 0)
		{
			arrSum = 0;
		}
		else if (arrSum >= maxArrSum)
		{
			maxArrSum = arrSum;
		}
	}
	return maxArrSum;
}