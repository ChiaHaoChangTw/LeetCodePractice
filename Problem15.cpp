class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(nums[l] + nums[r] == target) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    ++l, --r;
                }
                else if(nums[l] + nums[r] < target) {
                    ++l;
                }
                else {
                    --r;
                }
                while(l > i + 1 && l < r && nums[l] == nums[l - 1]) {
                    ++l;
                }
                while(r < nums.size() - 1 && l < r && nums[r] == nums[r + 1]) {
                    --r;
                }
            }
        }
        return result;
    }
};

// -nums[i] == nums[j] + nums[k]
// loop i loop j k as l r
// sort and skip duplicate

// no-sort solution

// Time: O(n ^ 2)
// Space: O(log n)

