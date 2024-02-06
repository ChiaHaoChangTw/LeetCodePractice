class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map<string, vector<string>> anagramStrsMap;
        for (const auto &str: strs) {
            anagramStrsMap[countingSort(str)].push_back(str);
        }
        for (const auto &[_, v]: anagramStrsMap) {
            groups.push_back(v);
        }
        return groups;
    }

private:
    string countingSort(const string &s) {
        string sorted = "";
        vector<int> charCount(26, 0);
        for (const auto &c: s) {
            ++charCount[c - 'a'];
        }
        for (int i = 0; i < charCount.size(); ++i) {
            sorted += string(charCount[i], i + 'a');
        }
        return sorted;
    }
};

// counting sort
// hash map
// time: O(n * l)
// space: O(n * l)

