class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string validString = "";
        string tempString = "";
        int balance = 0;
        int numOpen = 0;
        for (const auto &c: s) {
            if (c == '(') {
                ++balance;
                ++numOpen;
            } else if (c == ')' && balance == 0) {
                continue;
            } else if (c == ')') {
                --balance;
            }
            tempString += c;
        }
        int numOpenKeep = numOpen - balance;
        for (const auto &c: tempString) {
            if (c == '(' && numOpenKeep > 0) {
                --numOpenKeep;
            } else if (c == '(') {
                continue;
            }
            validString += c;
        }
        return validString;
    }
};

// stack
// time: O(n)
// space: O(n)

