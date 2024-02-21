// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         int shifts = 0;
//         while (left != right) {
//             left >>= 1;
//             right >>= 1;
//             ++shifts;
//         }
//         return left << shifts;
//     }
// };

// bit manipulation
// time: O(1)
// space: O(1)

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right &= (right - 1);
        }
        return left & right;
    }
};

// bit manipulation
// time: O(1)
// space: O(1)

