/*
** https://leetcode.com/problems/palindromic-substrings/submissions/
 */
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int matrix[n][n];
        int count = n;
        for(int i = 0; i < n; i++)
            matrix[i][i] = 1;
        for(int i = 0; i < (n-1); i++){
            if(s[i] == s[i + 1]){
                matrix[i][i + 1] = 1;
                count++;
            }
            else
                matrix[i][i + 1] = 0;
        }
        for(int k = 2; k < n; k++){
            for(int i = 0; i < (n - k); i++) {
                if(s[i] == s[i + k] && matrix[i + 1][i + k - 1]){
                    matrix[i][i + k] = 1;
                    count++;
                }
                else
                    matrix[i][i + k] = 0;
                           
            }
        }
        return count;
    }
};