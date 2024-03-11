class Solution {
public:
    string customSortString(string order, string s) {
        string sorted = "";
        unordered_map<char, int> charCount;
        for (const auto &c: s) {
            ++charCount[c];
        }
        for (const auto &c: order) {
            if (charCount.count(c)) {
                for (int k = 0; k < charCount[c]; ++k) {
                    sorted += c;
                }
                charCount.erase(c);
            }
        }
        for (const auto &[c, count]: charCount) {
            for (int k = 0; k < charCount[c]; ++k) {
                sorted += c;
            }
        }
        return sorted;
    }
};

// hash map
// time: O(n)
// space: O(1)

