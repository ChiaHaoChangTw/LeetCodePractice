class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> charCount(26, 0);
        int maxFreq = 0;
        int maxFreqCount = 0;
        for (const auto &task: tasks) {
            ++charCount[task - 'A'];
        }
        for (const auto &count: charCount) {
            if (count > maxFreq) {
                maxFreq = count;
                maxFreqCount = 1;
            } else if (count == maxFreq) {
                ++maxFreqCount;
            }
        }
        return max(int(tasks.size()), (maxFreq - 1) * (n + 1) + maxFreqCount);
    }
};

// greedy
// time: O(n)
// space: O(1)

