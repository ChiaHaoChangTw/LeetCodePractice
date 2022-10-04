class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSelect(nums, k);
        return nums[nums.size() - k];
    }
    
private:
    void quickSelect(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r) {
            mid = partition(nums, l, r);
            if(mid < nums.size() - k) {
                l = mid + 1;
            } else if(mid > nums.size() - k) {
                r = mid - 1;
            } else {
                break;
            }
        }
    }
    
    int partition(vector<int>& nums, int l, int r) {
        int pivot = l + rand() % (r - l + 1), partition = l;
        swap(nums[pivot], nums[r]);
        for(int i = l; i <= r; ++i) {
            if(nums[i] < nums[r]) {
                swap(nums[i], nums[partition]);
                ++partition;
            }
        }
        swap(nums[r], nums[partition]);
        return partition;
    }
};

