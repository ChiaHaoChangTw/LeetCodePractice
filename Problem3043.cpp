class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxLen = 0;
        unordered_set<int> prefixs;
        for (auto &num: arr1) {
            while (num) {
                prefixs.insert(num);
                num /= 10;
            }
        }
        for (auto &num: arr2) {
            while (num) {
                if (prefixs.count(num)) {
                    maxLen = max(maxLen, int(to_string(num).size()));
                    break;
                }
                num /= 10;
            }
        }
        return maxLen;
    }
};
