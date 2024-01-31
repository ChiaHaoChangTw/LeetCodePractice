// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int> warmerIndices(temperatures.size(), 0);
//         stack<int> decStk;
//         for (int i = 0; i < temperatures.size(); ++i) {
//             while (!decStk.empty() && temperatures[decStk.top()] < temperatures[i]) {
//                 warmerIndices[decStk.top()] = (i - decStk.top());
//                 decStk.pop();
//             }
//             decStk.push(i);
//         }
//         return warmerIndices;
//     }
// };

// stack
// time: O(n)
// space: O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> warmerIndices(temperatures.size(), 0);
        int warmest = 0;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            if (temperatures[i] >= warmest) {
                warmest = temperatures[i];
                continue;
            }
            int days = 1;
            while (temperatures[i + days] <= temperatures[i]) {
                days += warmerIndices[i + days];
            }
            warmerIndices[i] = days;
        }
        return warmerIndices;
    }
};

// space optimized
// traverse backward
// time: O(n)
// space: O(1)

