class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charCount(26, 0);
        for (const auto &c: s) {
            ++charCount[c - 'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (charCount[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

// vector as hash map
// time: O(n)
// space: O(1)

