class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> lower(n), higher(n);
        lower[n - 1] = true, higher[n - 1] = true;
        int result = 1;
        map<int, int> arrMap;
        arrMap[arr[n - 1]] = n - 1;
        for(int i = n - 2; i >= 0; --i) {
            auto hiIt = arrMap.lower_bound(arr[i]), loIt = arrMap.upper_bound(arr[i]);
            if(hiIt != arrMap.end()) {
                higher[i] = lower[hiIt->second];
            }
            if(loIt != arrMap.begin()) {
                lower[i] = higher[(--loIt)->second];
            }
            if(higher[i]) {
                ++result;
            }
            arrMap[arr[i]] = i;
        }
        return result;
    }
};

// dynamic programming
// map
// Time: O(n log n)
// Space: O(n)

// sub-problems
// higher(i) -> true if can reach
// lower(i) -> true if can reach

// recursion formula
// higher(i) = lower(j) = ...
// lower(i) = higher(j) = ...
