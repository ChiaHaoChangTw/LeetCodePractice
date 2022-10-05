class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(points, k);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    
private:
    void quickSelect(vector<vector<int>>& points, int k) {
        int l = 0, r = points.size() - 1, mid;
        while(l <= r) {
            mid = partition(points, l, r);
            if(mid < k - 1) {
                l = mid + 1;
            } else if(mid > k - 1) {
                r = mid - 1;
            } else {
                break;
            }
        }
    }
    
    int partition(vector<vector<int>>& points, int l, int r) {
        int pivot = l + rand() % (r - l + 1), partition = l;
        swap(points[pivot], points[r]);
        for(int i = l; i <= r; ++i) {
            if(distance(points[i]) < distance(points[r])) {
                swap(points[i], points[partition]);
                ++partition;
            }
        }
        swap(points[partition], points[r]);
        return partition;
    }
    
    int distance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};

