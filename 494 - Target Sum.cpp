/*
** https://leetcode.com/problems/target-sum/
 */

class Solution {
public:
    map<pair<int, int>, int> m;
    int sum = 0;
    long long int rec(int right, vector<int>& nums, unsigned int target) {
        if(m.find(make_pair(right, target)) != m.end())
            return m[make_pair(right, target)];
        if(right < 0) 
            return (target == 0);
        long long int ans = rec(right - 1, nums, target - nums[right]);
        ans = ans + rec(right - 1, nums, target + nums[right]);
        m[make_pair(right, target)] = ans;
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return rec(nums.size() - 1, nums, S);
    }
};