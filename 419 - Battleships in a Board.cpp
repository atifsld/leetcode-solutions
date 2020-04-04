/*
 * https://leetcode.com/problems/battleships-in-a-board/
 */
class Solution {
public:
    void dfs(vector<vector<char> >& board, int i, int j){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 46)
            return;
        board[i][j] = 46;
        dfs(board, i, j + 1);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i - 1, j);
        return;
    }
    int countBattleships(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return 0;
        int result = 0;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 88) {
                    result++;
                    dfs(board, i, j);
                }
            }
        }
        return result;
    }
};