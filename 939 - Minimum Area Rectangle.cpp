/*
** https://leetcode.com/problems/minimum-area-rectangle/
 */
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int min_area = INT_MAX;
        unordered_set<int> s;
        for(vector<int> point: points)
            s.insert(40001 * point[0] + point[1]);
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                if(s.find(40001 * points[i][0] + points[j][1]) != s.end() &&
                   s.find(40001 * points[j][0] + points[i][1]) != s.end()) {
                    int area = abs((points[i][0] - points[j][0]) * (points[i][1] - points[j][1]));
                    min_area = min(min_area, area);
                }
                
            }
        }
        return (min_area == INT_MAX) ?  0 : min_area;
    }
};