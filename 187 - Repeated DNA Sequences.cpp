/*
** https://leetcode.com/problems/repeated-dna-sequences/
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> sol;
        if(n < 11)
            return sol;
        set<string> string_set;
        set<string> sol_set;
        string_set.insert(s.substr(0, 10));
        for(int i = 10; i < s.length(); i++) {
            string repeat = s.substr(i - 9, 10);
            if(string_set.find(repeat) == string_set.end())
                string_set.insert(repeat);
            else
                sol_set.insert(repeat);
        }
        for(string x: sol_set)
            sol.push_back(x);
        return sol;
    }
};