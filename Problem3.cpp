class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1);
        int maxLen = 0;
        int l = 0;

        for (int r = 0; r < s.size(); ++r) {
            if (lastIndex[s[r]] >= l) {
                l = lastIndex[s[r]] + 1;    
            }
            lastIndex[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

// sliding window
// last index
// time O(n)
// space O(1) 128 ASCII

