class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        int lMax = 0;
        int rMax = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l <= r) {
            if (height[l] <= height[r]) {
                area += max(min(lMax, height[r]) - height[l], 0);
                lMax = max(lMax, height[l]);
                ++l;
            } else {
                area += max(min(rMax, height[l]) - height[r], 0);
                rMax = max(rMax, height[r]);
                --r;
            }
        }
        return area;
    }
};

// two pointers
// time: O(n)
// space: O(1)

