class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        unordered_map<int, int> subMap;
        for(auto& num: nums) {
            ++freqMap[num];
        }
        
        for(auto& num: nums) {
            if(freqMap[num] == 0) {
                continue;
            }
            if(subMap[num - 1] > 0) {
                --subMap[num - 1];
                ++subMap[num];
                --freqMap[num];
            }
            else if(freqMap[num + 1] > 0 && freqMap[num + 2] > 0) {
                ++subMap[num + 2];
                --freqMap[num];
                --freqMap[num + 1];
                --freqMap[num + 2];
            }
            else {
                return false;
            }
        }
        
        return true;
    }
};
