/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

// class Solution {
// public:
//     int search(const ArrayReader& reader, int target) {
//         if (target < reader.get(0)) {
//             return -1;
//         }
//         if (target == reader.get(0)) {
//             return 0;
//         }
//         int l = 1;
//         int r = target - reader.get(0);
//         int m = 1;
//         while (l <= r) {
//             m = l + (r - l) / 2;
//             if (reader.get(m) == target) {
//                 return m;
//             } else if (reader.get(m) > target) {
//                 r = m - 1;
//             } else if (reader.get(m) < target) {
//                 l = m + 1;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        if (reader.get(0) == target) {
            return 0;
        }
        int l = 0;
        int r = 1;
        int m = 0;
        while (reader.get(r) < target) {
            l = r + 1;
            r *= 2;
        }
        while (l <= r) {
            m = l + (r - l) / 2;
            if (reader.get(m) == target) {
                return m;
            } else if (reader.get(m) > target) {
                r = m - 1;
            } else if (reader.get(m) < target) {
                l = m + 1;
            }
        }
        return -1;
    }
};

// binary search
// time: O(log T)
// space: O(1)

