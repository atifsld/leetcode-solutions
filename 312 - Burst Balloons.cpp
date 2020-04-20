/*
** https://leetcode.com/problems/burst-balloons/
 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int n = nums.size();
        vector<int> A(1, 1);
        for(int num: nums)
            A.push_back(num);
        A.push_back(1);
        vector<vector<int> > dp(n + 1, vector<int>(n + 1));
        /*
            Weird loop below is needed to ensure that
            Before dp[left][right] is calculated,
                all dp[left][i] & dp[i + 1][right] is calculated.
        */
        for(int left = n; left >= 1; left--) {
            for(int right = left; right <= n; right++) {
                if(left == right) 
                    dp[left][right] = A[left - 1] * A[left] * A[left + 1];
                else{
                    dp[left][right] = A[left - 1] * A[left] * A[right + 1] + dp[left + 1][right];
                    dp[left][right] = max(dp[left][right], A[left - 1] * A[right] * A[right + 1] + dp[left][right - 1]);
                    for(int p = left + 1; p < right; p++) {
                        dp[left][right] = max(dp[left][right], dp[left][p - 1] + dp[p + 1][right] + A[left - 1] * A[p] * 
                        A[right+ 1 ]);
                    }
                }
            }
        }
        return dp[1][n];
    }
};