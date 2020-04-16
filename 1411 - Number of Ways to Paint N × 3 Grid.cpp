/*
** https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
 */
class Solution {
public:
    int MOD = 1000000007;
    int numOfWays(int n) {
        long long temp_two, two = 6, three = 6;
        for(int i = 2; i <= n; i++) {
            temp_two = two;
            two = (two * 3 + three * 2) % MOD;
            three = (temp_two + three) * 2 % MOD;
        }
        return (two + three) % MOD;
    }
};