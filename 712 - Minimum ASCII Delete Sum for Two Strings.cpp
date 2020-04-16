/*
** https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
 */
class Solution {
public:
    int bottomUpDP(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        int dp[m + 1][n + 1];
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n ; j++) {
                if(i == 0 || j == 0) {
                    if(i == 0 && j == 0)
                        dp[i][j] = 0;
                    else if(i == 0)
                        dp[0][j] = dp[0][j - 1] + s2[j - 1];
                    else
                        dp[i][0] = dp[i - 1][0] + s1[i - 1];
                }
                else if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else 
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], 
                                   dp[i][j - 1] + s2[j - 1]);
            }
        }
        return dp[m][n];
    }
    int topDownDP(string &s1, string &s2, int i, int j) {
        if(i == -1 || j == -1) {
            if(i == -1 && j == -1)
                return 0;
            if(i == -1)
                return topDownDP(s1, s2, i, j - 1) + s2[j];
            return topDownDP(s1, s2, i - 1, j) + s1[i];
        }
        if(s1[i] == s2[j])
            return topDownDP(s1, s2, i - 1, j - 1);
        return min(topDownDP(s1, s2, i - 1, j) + s1[i], 
                   topDownDP(s1, s2, i, j - 1) + s2[j]);
        
    }
    int minimumDeleteSum(string s1, string s2) {
        return bottomUpDP(s1, s2);
        /*            
            return topDownDP(s1, s2, s1.length()-1, s2.length() - 1);
        */
    }
};