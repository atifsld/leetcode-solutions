/*
    https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/submissions/
*/
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int ways[target + 1][d + 1];
        memset(ways, 0, sizeof(int) * (target + 1) * (d + 1));
        for (int i = 0; i <= target; i++) {
            for (int j = 0; j <= d; j++) {
                if (i == 0 && j == 0) {
                    ways[i][j] = 1;
                    continue;
                }
                if (!(i == 0 || j == 0) && (j <= i))
                    for(int k = i - 1; k >= 0 && k >= i - f; k--)
                        ways[i][j] = (ways[i][j] + ways[k][j - 1]) % 1000000007;
            }
        }
        return ways[target][d];
    }
};