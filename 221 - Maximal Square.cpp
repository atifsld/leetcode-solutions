/*
     https://leetcode.com/problems/maximal-square/submissions/   
*/
class Solution {
public:
    int min(int x, int y, int z){
        return x < (y < z? y: z)? x: (y < z? y: z);
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        if(!matrix.size())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int dp[m][n];
        int result = 0;
        memset(dp, 0, sizeof(int) * m * n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1'){
                    if(i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]) + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result * result;
    }
};