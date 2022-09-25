class Solution {
public:
    string nextClosestTime(string time) {
        vector<char> chars;
        for(auto& t: time) {
            if(t != ':') {
                chars.push_back(t);
            }
        }
        sort(chars.begin(), chars.end());
        
        if(check4th(time, chars)) {
            return time;
        }
        if(check3rd(time, chars)) {
            return time;
        }
        if(check2nd(time, chars)) {
            return time;
        }
        check1st(time, chars);
        return time;
    }

private:
    bool check4th(string& time, vector<char>& chars) {
        auto ptr = upper_bound(chars.begin(), chars.end(), time[4]);
        if(ptr != chars.end()) {
            time[4] = *ptr;
            return true;
        }
        time[4] = chars[0];
        return false;
    }
    
    bool check3rd(string& time, vector<char>& chars) {
        auto ptr = upper_bound(chars.begin(), chars.end(), time[3]);
        if(ptr != chars.end() && *ptr < '6') {
            time[3] = *ptr;
            return true;
        }
        time[3] = chars[0];
        return false;
    }
    
    bool check2nd(string& time, vector<char>& chars) {
        auto ptr = upper_bound(chars.begin(), chars.end(), time[1]);
        if(ptr != chars.end() && (time[0] < '2' || *ptr < '4' && time[0] == '2')) {
            time[1] = *ptr;
            return true;
        }
        time[1] = chars[0];
        return false;
    }
    
    bool check1st(string& time, vector<char>& chars) {
        auto ptr = upper_bound(chars.begin(), chars.end(), time[0]);
        if(ptr != chars.end() && (*ptr < '2' || *ptr == '2' && time[1] < '4')) {
            time[0] = *ptr;
            return true;
        }
        time[0] = chars[0];
        return false;
    }
};
