class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long count = 0;
        int curr = 0;
        unordered_map<int, int> bitsCountMap = {{curr, 1}};
        for (const auto &w: word) {
            curr ^= (1 << w - 'a');
            for (int i = 'a' - 'a'; i <= 'j' - 'a'; ++i) {
                int target = curr ^ (1 << i);
                if (bitsCountMap.count(target)) {
                    count += bitsCountMap[target];
                }
            }
            if (bitsCountMap.count(curr)) {
                count += bitsCountMap[curr];
            }
            bitsCountMap[curr] += 1;
        }
        return count;
    }
};

// bit manipulation
// prefix sum
// hash map
// counting
// time: O(n * k)
// space: O(k)

