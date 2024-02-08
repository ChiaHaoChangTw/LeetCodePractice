class Solution {
public:
    int numWays(int n, int k) {
        int pp = k;
        int p = k * k;
        for (int i = 2; i < n; ++i) {
            int curr = (p + pp) * (k - 1);
            pp = p;
            p = curr;
        }
        return n == 1 ? pp : p;
    }
};

// dp
// time: O(n)
// space: O(1)

