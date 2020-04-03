/*
 * https://leetcode.com/problems/word-search/
 */
class Solution {
public:
    int steps[4][2];
    void init_steps() {
        steps[0][0] =  0; steps[0][1] =  1;
        steps[1][0] =  1; steps[1][1] =  0;
        steps[2][0] =  0; steps[2][1] = -1;
        steps[3][0] = -1; steps[3][1] =  0;
    }
    
    bool backtracker(vector<vector<char> >& board, string& word, int i, int j, int index) {
        if(board[i][j] != word[index])
            return false;
        if(index == word.size() - 1)
            return true;
        board[i][j] = '0';
        for(int i=0; i<4; i++) {
            if(i + steps[i][0] >= 0 && i + steps[i][0] <  board.size() &&
               j + steps[i][1] >= 0 && j + steps[i][1] <  board[0].size() &&
               backtracker(board, word, i+steps[i][0], j+steps[i][1], index+1))
                return true;
        }
        board[i][j] = word[index];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        init_steps();
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(backtracker(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};