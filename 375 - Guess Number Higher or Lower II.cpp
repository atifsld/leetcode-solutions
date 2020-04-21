/*
** https://leetcode.com/problems/guess-number-higher-or-lower-ii/
 */
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for(int i = 0; i < (n-1); i++)
            dp[i][i+1] = i+1;
        for(int gap = 2; gap < n; gap++) {
            for(int left = 0; left < (n - gap); left++) {
                int right = left + gap;
                dp[left][right] = (left + 1) + dp[left + 1][right];
                dp[left][right] = min(dp[left][right], 
                                      (right + 1) + dp[left][right - 1]);
                for(int p = left + 1; p < right; p++) {
                    dp[left][right] = min(dp[left][right], 
                                          max(dp[left][p - 1], dp[p + 1][right]) + (p + 1));
                }
            }
        }
        return dp[0][n - 1];
    }
};