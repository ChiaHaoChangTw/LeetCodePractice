class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxLen = 0;
        unordered_map<char, int> charCountMap;
        for (int i = 0; i < s.size(); ++i) {
            ++charCountMap[s[i]];
            if (charCountMap.size() <= k) {
                ++maxLen;
            } else {
                --charCountMap[s[i - maxLen]];
                if (charCountMap[s[i - maxLen]] == 0) {
                    charCountMap.erase(s[i - maxLen]);
                }
            }
        }
        return maxLen;
    }
};

// sliding window
// time: O(n)
// space: O(k)

