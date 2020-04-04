/*
 * https://leetcode.com/problems/subsets/
 */
class Solution {
public:
    vector<vector<int> > solution;
    vector<int> workingSet;
    void backtracker(const vector<int>& nums, int position, const int &size){
    
        if(position==size){
            solution.push_back(workingSet);
            return;
        }
        
        backtracker(nums, position+1, size);
        workingSet.push_back(nums[position]);
        backtracker(nums, position+1, size);
        workingSet.pop_back();
        return;
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        //int len = nums.size();
        backtracker(nums, 0, nums.size());
        return solution;
    }
};