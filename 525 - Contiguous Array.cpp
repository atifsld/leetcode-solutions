/*
 * https://leetcode.com/problems/contiguous-array/
 */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int counts[(2 * n) + 1];
        int count = 0;
        for(int i = 0; i < (2 * n) + 1; i++)
            counts[i] = INT_MAX;
        counts[n] = -1; 
        for(int i = 0; i < n; i++) {
            count += (nums[i]==1)? 1: -1;            
            if(counts[count + n] == INT_MAX)          
                counts[count + n] = i;
            else
                ans = max(ans, i - counts[count + n]);
        }
        return ans;
    }
};