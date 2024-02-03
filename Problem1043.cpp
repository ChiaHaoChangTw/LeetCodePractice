class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> memo(arr.size(), -1);
        return par(arr, k, 0, memo);
    }

private:
    int par(vector<int> &arr, int k, int i, vector<int> &memo) {
        if (i >= arr.size()) {
            return 0;
        }
        if (memo[i] >= 0) {
            return memo[i];
        }
        int maxVal = INT_MIN;
        for (int j = i; j < i + k && j < arr.size(); ++j) {
            maxVal = max(maxVal, arr[j]);
            memo[i] = max(memo[i], 
                          maxVal * (j - i + 1) + par(arr, k, j + 1, memo));
        }
        return memo[i];
    }
};

// memo dp
// time: O(n * k)
// space: O(n)

