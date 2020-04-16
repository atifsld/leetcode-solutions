/*
** https://leetcode.com/problems/distinct-subsequences/
 */
class Solution {
public:
    bool same_string(string& s, string& t) {
        for(int i = 0; i < s.length(); i++)
            if(s[i] != t[i])
                return false;
        return true;
    }
    int numDistinct(string s, string t) {
        if(t.length() >= s.length()){
            if(t.length() > s.length())
                return 0;
            return same_string(s, t);
        }
        int T = t.length();
        int S = s.length();
        unsigned int dp[T + 1][S +1 ];
        for(int j = 0; j <= S; j++)
            dp[0][j] = 1;
        
        for(int i = 1; i <= T; i++) {
            for(int j = 0; j <= S; j++) {
                if(i > j)
                    dp[i][j] = 0;
                else if(t[i - 1] == s[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[T][S];
    }
};