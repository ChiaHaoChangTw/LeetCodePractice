class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int result = 0;
        for(auto& word: words) {
            if(isStretchy(s, word)) {
                ++result;
            }
        }
        return result;
    }
    
private:
    bool isStretchy(string& s, string& word) {
        int sPtr = 0, wPtr = 0;
        while(sPtr < s.size() && wPtr < word.size()) {
            if(s[sPtr] != word[wPtr]) {
                return false;
            }
            int sCount = 1, wCount = 1;
            ++sPtr, ++wPtr;
            while(sPtr < s.size() && s[sPtr] == s[sPtr - 1]) {
                ++sPtr, ++sCount;
            }
            while(wPtr < word.size() && word[wPtr] == word[wPtr - 1]) {
                ++wPtr, ++wCount;
            }
            if(sCount < wCount || sCount > wCount && sCount < 3) {
                return false;
            }
        }
        return sPtr == s.size() && wPtr == word.size();
    }
};

// Two Pointers

// Time: O(ls * lw * n)
// Space: O(1)

