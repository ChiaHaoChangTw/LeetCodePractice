class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        long long count = 0;
        vector<int> diffs;
        for (int i = 0; i < nums1.size(); ++i) {
            diffs.push_back(nums1[i] - nums2[i]);
        }
        sort(diffs.begin(), diffs.end());
        int l = 0;
        int r = diffs.size() - 1;
        while (l < r) {
            if (diffs[l] + diffs[r] > 0) {
                count += r - l;
                --r;
            } else {
                ++l;
            }
        }
        return count;
    }
};

// sort
// two pointers
// time: O(n log n)
// space: O(n)

