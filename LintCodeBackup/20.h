#pragma once
#include "header.h"
class Solution {
public:
	/**
	* @param n an integer
	* @return a list of pair<sum, probability>
	*/
	vector<pair<int, double>> dicesSum(int n) {
		// Write your code here
		vector<vector<long long>> dp(n + 1, vector<long long>(n * 6 + 2, 0));
		for (int i = 1;i <= 6;i++) {
			dp[1][i] = 1;
		}
		for (int i = 2;i <= n;i++) {
			for (int j = i;j < 6 * n + 1;j++) {
				for (int k = 0;k < 6;k++) {
					dp[i][j + k] += dp[i - 1][j - 1];
				}
			}
		}
		vector<pair<int, double>> result;
		long long sum = 0;
		for (int i = n;i <= n * 6;i++) {
			sum += dp[n][i];
		}
		for (int i = n;i <= n * 6;i++) {
			result.push_back(make_pair(i, (double)1.0*dp[n][i] / sum));
		}
		return result;
	}
};