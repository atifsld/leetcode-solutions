/*
** https://leetcode.com/problems/longest-palindromic-subsequence/
 */
class Solution {
public:
    /*
        Top-down dynamic programming solution
    
    int n;
    int lps(string& s, int l, int r, int dp[]) {
        if(dp[n * l + r] != -1)
            return dp[n * l + r];
        if(s[l] == s[r])
            dp[n * l + r] = 2 + lps(s, l + 1, r - 1, dp);
        else
            dp[n * l + r] = max(lps(s, l + 1, r, dp), lps(s, l , r - 1, dp));
        return dp[n * l + r];
            
    }
    int longestPalindromeSubseq(string s) {
        n = s.length();
        int dp[n * n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j)
                    dp[n * i + j] = 1;
                else if(i+1 == j)
                    dp[n * i + j] = (s[i] == s[j])? 2: 1;
                else
                    dp[n * i + j] = -1;
            }
        }
        
        return lps(s, 0, n-1, dp);
    }
    */
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n][n];
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if(i != n - 1)
                dp[i][i + 1] = (s[i] == s[i + 1]) ? 2 : 1;
        }
        for(int d = 2; d < n; d++) {
            for(int i = 0; i < (n -d); i++) {
                if(s[i] == s[i + d])
                    dp[i][i + d] = 2 + dp[i + 1][i + d - 1];
                else
                    dp[i][i + d] = max(dp[i + 1][i + d], dp[i][i + d - 1]);
            }
        }
        return dp[0][n-1];
    }
};