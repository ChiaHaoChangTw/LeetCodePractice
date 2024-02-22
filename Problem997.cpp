class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() < n - 1) {
            return -1;
        }
        vector<int> trustScores(n + 1, 0);
        for (const auto &t: trust) {
            --trustScores[t[0]];
            ++trustScores[t[1]];
        }
        for (int i = 1; i < trustScores.size(); ++i) {
            if (trustScores[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};

// one vector
// time: O(m)
// space: O(n)

