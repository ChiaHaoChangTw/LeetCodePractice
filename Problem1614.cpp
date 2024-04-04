class Solution {
public:
    int maxDepth(string s) {
        int maxDep = 0;
        int currDep = 0;
        for (const auto &c: s) {
            if (c == '(') {
                ++currDep;
                maxDep = max(maxDep, currDep);
            } else if (c == ')') {
                --currDep;
            }
        }
        return maxDep;
    }
};

// counting
// time: O(n)
// space: O(1)

