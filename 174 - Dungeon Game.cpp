/*
      https://leetcode.com/problems/dungeon-game/
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        int costs[m+1][n+1];
        for (int i = 0; i <= m; i++)
            costs[i][n] = INT_MAX;
        for (int i = 0; i <= n; i++) 
            costs[m][i] = INT_MAX;
        costs[m][n - 1] = 1;
        costs[m - 1][n] = 1;
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                costs[i][j] = min(costs[i + 1][j], costs[i][j + 1]) - dungeon[i][j];
                if(costs[i][j] <= 0)
                    costs[i][j] = 1;
            }
        }
        return costs[0][0];
    }
};