/*
** https://leetcode.com/problems/merge-intervals/
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<vector<int> > st;
        vector<vector<int> > sol;
        
        sort(intervals.begin(), intervals.end());
        
        for(vector<int> interval: intervals) {
            if(st.empty() || interval[0] > st.top()[1]) {
                st.push(interval);
                continue;
            }
            vector<int> top = st.top();
            st.pop();
            top[1] = max(top[1], interval[1]);
            st.push(top);            
        }        
        while(!st.empty()) {
            sol.push_back(st.top());
            st.pop();
        }
        return sol;
    }
};