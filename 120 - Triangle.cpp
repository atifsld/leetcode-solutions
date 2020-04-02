/*
    https://leetcode.com/problems/triangle/
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int result, layers = triangle.size();
        int costs[layers][layers];
        costs[0][0] = triangle[0][0];
        for (int depth = 1; depth < layers; depth++){
            for (int i = 0; i <= depth; i++){
                if (i == 0)
                    costs[depth][0] = triangle[depth][0] + costs[depth-1][0];
                else if (i == depth)
                    costs[depth][depth] = triangle[depth][depth] + costs[depth - 1][depth - 1]; 
                else
                    costs[depth][i] = triangle[depth][i] + min(costs[depth - 1][i], costs[depth - 1][i - 1]);
            }
        }
        result = costs[layers-1][0];
        for (int i = 0; i < layers; i++)
            if (costs[layers - 1][i] < result)
                result = costs[layers - 1][i];
        return result;
    }
};