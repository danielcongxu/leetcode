#include <iostream>
#include <vector>
using namespace std;


// Divide and Conquer algorithm, accepted on O(nlogn)
int _getMaxSumOfSubSeq(vector<int>& arr, int left, int right)
{
	if (left == right)
	{
		return arr[left];
	}
	
	int center = (left + right) / 2;
	int maxLeftSum = _getMaxSumOfSubSeq(arr, left, center);
	int maxRightSum = _getMaxSumOfSubSeq(arr, center + 1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for (int i = center; i >= left; i--)
	{
		leftBorderSum += arr[i];
		if (leftBorderSum > maxLeftBorderSum)
		{
			maxLeftBorderSum = leftBorderSum;
		}
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for (int i = center+1; i <= right; i++)
	{
		rightBorderSum += arr[i];
		if (rightBorderSum > maxRightBorderSum)
		{
			maxRightBorderSum = rightBorderSum;
		}
	}

	if (maxLeftSum > maxRightSum)
	{
		return (maxLeftBorderSum + maxRightBorderSum) > maxLeftSum ? maxLeftBorderSum + maxRightBorderSum : maxLeftSum;
	}
	else
	{
		return (maxLeftBorderSum + maxRightBorderSum) > maxRightSum ? maxLeftBorderSum + maxRightBorderSum : maxRightSum;
	}
}

int getMaxSumOfSubSeq(vector<int>& arr)
{
	return _getMaxSumOfSubSeq(arr, 0, arr.size() - 1);
}
