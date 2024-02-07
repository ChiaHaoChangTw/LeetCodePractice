class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> charCount;
        for (const auto &c: s) {
            ++charCount[c];
        }
        sort(s.begin(), s.end(), 
            [&charCount](const char &c1, const char &c2){
                if (charCount[c1] == charCount[c2]) {
                    return c1 > c2;
                }
                return charCount[c1] > charCount[c2];
            });
        return s;
    }
};

// 1102-1122
// time: O(n log n)
// space: O(log n)

