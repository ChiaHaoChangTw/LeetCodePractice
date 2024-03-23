class Solution {
public:
    string removeVowels(string s) {
        string removed = "";
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (const auto &c: s) {
            if (!vowels.count(c)) {
                removed += c;
            }
        }
        return removed;
    }
};

// hash set
// time: O(n)
// space: O(1)

