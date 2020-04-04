/*
** https://leetcode.com/problems/number-of-islands/
 */
class Solution {
public:
    void dfs(vector<vector<char> >& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 48)
            return;
        grid[i][j] = 48;
        dfs(grid, i, j + 1);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i - 1, j);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int result = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 49) {
                    result++;
                    dfs(grid, i, j);
                }
            }
        }
        return result;
    }
};