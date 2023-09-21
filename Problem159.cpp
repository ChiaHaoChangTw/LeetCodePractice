class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int result = 1;
        unordered_map<char, int> charLastIndexMap;

        for (int l = 0, r = 0; r < s.size(); ++r) {
            charLastIndexMap[s[r]] = r;
            if (charLastIndexMap.size() > 2) {
                auto min_it = min_element(charLastIndexMap.begin(), charLastIndexMap.end(), 
                                            [](auto l, auto r){return l.second < r.second;});
                l = min_it->second + 1;
                charLastIndexMap.erase(min_it);
            } else {
                result = max(result, r - l + 1);
            }
        }

        return result;
    }
};

// 2 pointers
// hash: char - last index
// time O(n)
// space O(1)

