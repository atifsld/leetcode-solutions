/*
    https://leetcode.com/problems/minimum-cost-for-tickets/
*/
int min(int a, int b, int c){
    return std::min(a, std::min(b, c));
}

class Solution {
public:
    int memo[365];
    set<int> day_set;
    void populate_day_set(vector<int>& days) {
        for(int day: days)
            if(day_set.find(day) == day_set.end())
                day_set.insert(day);
    }
    int dp(int x, vector<int>& costs){
        if(x>365)
            return 0;
        if(memo[x - 1] != -1)
            return memo[x -1 ];
        if(day_set.find(x) == day_set.end()){
            memo[x - 1] = dp(x + 1, costs);
            return memo[x - 1];
        }
        memo[x - 1] = min(dp(x + 1, costs) + costs[0],
                      dp(x + 7, costs) + costs[1],
                      dp(x + 30, costs) + costs[2]);
        return memo[x - 1];
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(memo, -1, sizeof(memo));
        populate_day_set(days);
        return dp(1, costs);
        
    }
};