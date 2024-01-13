class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0;
        vector<int> charCount(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++charCount[s[i] - 'a'];
            --charCount[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            count += max(charCount[i], 0);
        }
        return count;
    }
};

// vector as hash map
// time: O(n)
// space: O(1)

