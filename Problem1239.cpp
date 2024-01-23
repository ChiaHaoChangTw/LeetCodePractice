class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxLen = 0;
        back(arr, 0, "", maxLen);
        return maxLen;
    }

private:
    void back(const vector<string> &arr, int i, string curr, int &maxLen) {
        if (i >= arr.size()) {
            if (isUnique(curr)) {
                maxLen = max(maxLen, int(curr.size()));
            }
            return;
        }
        if (curr.size() > 26) {
            return;
        }
        back(arr, i + 1, curr + arr[i], maxLen);
        back(arr, i + 1, curr, maxLen);
    }

    bool isUnique(string &s) {
        if (s.size() > 26) {
            return false;
        }
        vector<bool> visited(26, false);
        for (const auto &c: s) {
            if (visited[c - 'a']) {
                return false;
            }
            visited[c - 'a'] = true;
        }
        return true;
    }
};

// recursion
// time: O(2 ^ n)
// space: O(n)

