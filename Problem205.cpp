class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> from;
        unordered_map<char, char> to;
        for (int i = 0; i < s.size(); ++i) {
            if (!from.count(s[i]) && !to.count(t[i])) {
                from[s[i]] = t[i];
                to[t[i]] = s[i];
            } else if (from[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};

// hash map
// time: O(n)
// space: O(1)

