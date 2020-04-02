/*
	https://leetcode.com/problems/ones-and-zeroes/
*/
class Solution {
public:
    vector<vector<int> > counts;
    unordered_map<int , int> memo;
    vector<int> zerosAndOnes(string& S) {
        vector<int> result(2);
        int zeroes = 0;
        for(char c: S)
            if(c=='0')
                zeroes++;
        result[0] = zeroes;
        result[1] = S.length() - zeroes;
        return result;        
    }
    int inMap(int zeros, int ones, int n) {
        int key = zeros * 1000000 + ones * 1000 + n;
        if(memo.find(key) != memo.end())
            return memo[key];
        return -1;
    }
    int rec(int zeros, int ones, int n) {
        int saved = inMap(zeros, ones, n);
        if(saved != -1)
            return saved;
        if(zeros<0 || ones < 0)
            return -1;
        if(n==counts.size())
            return 0;
        int result =  max(
            rec(zeros, ones, n + 1), 
            1 + rec(zeros - counts[n][0], ones - counts[n][1], n + 1));
        int key = zeros * 1000000 + ones * 1000 + n;
        memo[key] = result;
        return result;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        for (string S: strs)
            counts.push_back(zerosAndOnes(S));
        return rec(m, n, 0);
        
    }
};