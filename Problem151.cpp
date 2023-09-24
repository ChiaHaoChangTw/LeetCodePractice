class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int fillIdx = 0;
        for (int l = 0; l < s.size(); ++l) {
            if (s[l] != ' ') {
                int r = l;
                while (r < s.size() && s[r] != ' ') {
                    s[fillIdx++] = s[r++];
                }
                reverse(s.begin() + fillIdx - (r - l), s.begin() + fillIdx);
                if (fillIdx < s.size()) {
                    s[fillIdx] = ' ';
                }
                ++fillIdx;
                l = r;
            }
        }

        s.erase(s.begin() + fillIdx - 1, s.end());

        return s;
    }
};

// reverse
// reverse and skip spaces
// time O(n)
// space O(1)

