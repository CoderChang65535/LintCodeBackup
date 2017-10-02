#pragma once
#include "header.h"
class Solution {
public:
	/*
	* @param nums: an array of Integer
	* @param target: target = nums[index1] + nums[index2]
	* @return: [index1 + 1, index2 + 1] (index1 < index2)
	*/
	vector<int> twoSum(vector<int> &nums, int target) {
		// write your code here
		map<int, int> _map;
		int len = nums.size();
		_map.insert(make_pair(nums[0], 0));
		for (int i = 1;i < len;i++) {
			int value = target - nums[i];
			if (_map.find(value) != _map.end()) {
				vector<int> result;
				result.push_back(_map[value]+1);
				result.push_back(i+1);
				return result;
			}
			else {
				_map.insert(make_pair(nums[i], i));
			}
		}
	}
};