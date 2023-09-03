class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        auto l = s.begin();
        auto r = l;
        while (l < s.end()) {
            while (r < s.end() && *r != ' ') {
                ++r;
            }
            reverse(l, r);
            ++r;
            l = r;
        }
    }
};

// reverse
// time O(n)
// space O(1)

