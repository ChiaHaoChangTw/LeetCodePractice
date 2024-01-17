class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> numCountMap;
        unordered_set<int> countSet;
        for (const auto &num: arr) {
            ++numCountMap[num];
        }
        for (const auto &[_, v]: numCountMap) {
            if (countSet.count(v)) {
                return false;
            }
            countSet.insert(v);
        }
        return true;
    }
};

// hash map
// hash set
// time: O(n)
// space: O(n)

