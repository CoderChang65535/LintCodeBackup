#pragma once
#include "header.h"
class Solution {
public:
	/*
	* @param num: a non-negative integer
	* @return: one digit
	*/
	int addDigits(int num) {
		// write your code here
		string s = to_string(num);
		int len = s.length();
		while (len > 1) {
			int sum = 0;
			for (int i = 0;i < len;i++) {
				sum += s[i] - '0';
			}
			s = to_string(sum);
			len = s.length();
		}
		return s[0] - '0';
	}
};