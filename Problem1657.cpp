class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        vector<int> charCount1(26, 0);
        vector<int> charCount2(26, 0);
        int charBits1 = 0;
        int charBits2 = 0;
        for (int i = 0; i < word1.size(); ++i) {
            ++charCount1[word1[i] - 'a'];
            charBits1 |= (1 << (word1[i] - 'a'));
            ++charCount2[word2[i] - 'a'];
            charBits2 |= (1 << (word2[i] - 'a'));
        }
        sort(charCount1.begin(), charCount1.end());
        sort(charCount2.begin(), charCount2.end());
        return charBits1 == charBits2 && charCount1 == charCount2;
    }
};

// vector as hash map
// bit mask to store char set
// time: O(n)
// space: O(1)

