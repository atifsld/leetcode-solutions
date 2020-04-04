/*
 * https://leetcode.com/problems/single-number-ii/
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> hash_set;
        for(int num: nums)
            hash_set[num] = (hash_set.find(num) == hash_set.end())? 1: hash_set[num] + 1;
        for(auto entry: hash_set)
            if(entry.second < 3)
                return entry.first;
        return INT_MAX;
    }
};