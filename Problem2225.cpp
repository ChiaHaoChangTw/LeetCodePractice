// class Solution {
// public:
//     vector<vector<int>> findWinners(vector<vector<int>>& matches) {
//         vector<vector<int>> winners(2);
//         unordered_map<int, int> playerStateMap;
//         for (const auto &match: matches) {
//             if (!playerStateMap.count(match[0])) {
//                 playerStateMap[match[0]] = 0;
//             }
//             playerStateMap[match[1]] += 1;
//         }
//         for (const auto &[k, v]: playerStateMap) {
//             if (v == 0) {
//                 winners[0].push_back(k);
//             }
//             if (v == 1) {
//                 winners[1].push_back(k);
//             }
//         }
//         sort(winners[0].begin(), winners[0].end());
//         sort(winners[1].begin(), winners[1].end());
//         return winners;
//     }
// };

// hash map
// time: O(n log n)
// space: O(n)

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> winners(2);
        vector<int> count(100001, -1);
        for (const auto &match: matches) {
            if (count[match[0]] == -1) {
                count[match[0]] = 0;
            }
            if (count[match[1]] == -1) {
                count[match[1]] = 1;
            } else {
                count[match[1]] += 1;
            }
        }
        for (int i = 1; i < 100001; ++i) {
            if (count[i] == 0) {
                winners[0].push_back(i);
            }
            if (count[i] == 1) {
                winners[1].push_back(i);
            }
        }
        return winners;
    }
};

// counting sort
// time: O(n + k)
// space: O(k)

