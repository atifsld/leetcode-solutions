/*
 * https://leetcode.com/problems/my-calendar-ii/
 */
class MyCalendarTwo {
public:
    vector<pair<int, int> > bookings;
    vector<pair<int, int> > overlaps;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(pair<int, int> x: overlaps) {
            if(x.first < end && x.second > start)
                return false;
        }
        for(pair<int, int> x: bookings) {
            if(x.first < end && x.second > start)
                overlaps.push_back( make_pair(max(start, x.first), min(end, x.second)));
        }
        bookings.push_back(make_pair(start, end));
        return true;
    }
};