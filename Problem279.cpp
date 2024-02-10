class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }
        if (isSquare(n)) {
            return 1;
        }
        for (int i = 1; i * i < n; ++i) {
            if (isSquare(n - i * i)) {
                return 2;
            }
        }
        return 3;
    }

private:
    bool isSquare(int n) {
        int sqrtVal = int(sqrt(n));
        return sqrtVal * sqrtVal == n;
    }
};

// math
// time: O(sqrt n)
// space: o(1)

// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> squares;
//         unordered_set<int> bfsQueue;
//         int level = 1;
//         for (int i = 1; i * i <= n; ++i) {
//             squares.push_back(i * i);
//         }
//         bfsQueue.insert(n);
//         while (!bfsQueue.empty()) {
//             unordered_set<int> nextQueue;
//             for (const auto &rem: bfsQueue) {
//                 for (const auto& square: squares) {
//                     if (square == rem) {
//                         return level;
//                     } else if (rem < square) {
//                         break;
//                     } else if (rem > square) {
//                         nextQueue.insert(rem - square);
//                     }
//                 }
//             }
//             bfsQueue = nextQueue;
//             ++level;
//         }
//         return -1;
//     }
// };

// bfs

