class Solution {
public:
    int titleToNumber(string columnTitle) {
        int number = 0;
        for (auto c: columnTitle) {
            number = (number * 26) + (c - 'A' + 1);
        }
        return number;
    }
};

// traverse string * 26
// time O(n)
// space O(1)

