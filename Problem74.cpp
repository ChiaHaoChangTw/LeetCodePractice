class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1, mid;
        
        while(l <= r) {
            mid = l + (r - l) / 2;
            
            if(getVal(matrix, mid, n) == target) {
                return true;
            }
            
            else if(getVal(matrix, mid, n) > target) {
                r = mid - 1;
            }
            
            else {
                l = mid + 1;
            }
        }
        
        return false;
    }
    
private:
    int getVal(vector<vector<int>>& matrix, int index, int n) {
        return matrix[index / n][index % n];
    }
};
