class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        for(auto& interval: intervals) {
            starts.push_back(interval[0]), ends.push_back(interval[1]);
        }
        sort(starts.begin(), starts.end()), sort(ends.begin(), ends.end());
        
        int rooms = 0, endPos = 0;
        for(auto& start: starts) {
            if(start < ends[endPos]) {
                ++rooms;
            } else {
                ++endPos;
            }
        }
        
        return rooms;
    }
};

