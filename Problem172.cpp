class Solution {
public:
    int trailingZeroes(int n) {
        int numFive = 0;
        int fivePower = 5;
        while (fivePower <= n) {
            numFive += n / fivePower;
            fivePower *= 5;
        }
        return numFive;
    }
};

// how many 5 s
// time O(log n)
// space O(1)

