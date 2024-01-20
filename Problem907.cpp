class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long minSum = 0;
        const int MOD = 1e9 + 7;
        stack<int> incStk;
        for (int i = 0; i <= arr.size(); ++i) {
            while (!incStk.empty() && 
                   (i >= arr.size() || arr[incStk.top()] >= arr[i])) {
                int m = incStk.top();
                incStk.pop();
                int l = incStk.empty() ? -1 : incStk.top();
                int r = i;
                long currSum = (m - l) * (r - m) % MOD;
                minSum += (currSum * arr[m]) % MOD;
                minSum %= MOD;
            }
            incStk.push(i);
        }
        return minSum;
    }
};

// monotonic stack
// time: O(n)
// space: O(n)

