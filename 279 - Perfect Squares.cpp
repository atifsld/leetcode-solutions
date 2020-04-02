/*
    https://leetcode.com/problems/perfect-squares/
*/
class Solution {
public:
    
    int rec(int n, vector<int>& memo){
        if(memo[n] != INT_MAX)
            return memo[n];
        int result = INT_MAX;
        int i=1;
        while (pow(i, 2) <= n) {
            result = min(result, 1 + rec(n - pow(i, 2), memo));
            i++;
        }
        memo[n] = result;
        return memo[n];
    }
    int numSquares(int n) {
        vector<int> memo(n+1, INT_MAX);
        memo[0] = 0;
        return rec(n, memo);
    }
};