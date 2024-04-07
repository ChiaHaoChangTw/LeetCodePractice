class Solution {
public:
    bool checkValidString(string s) {
        int b = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*' || s[i] == '(') {
                ++b;
            } else if (s[i] == ')' && b > 0) {
                --b;
            } else {
                return false;
            }
        }
        b = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '*' || s[i] == ')') {
                ++b;
            } else if (s[i] == '(' && b > 0) {
                --b;
            } else {
                return false;
            }
        }
        return true;
    }
};

// 2 pass
// time: O(n)
// space: O(1)

