// class Solution {
// public:
//     string makeGood(string s) {
//         string goodString = "";
//         for (auto c: s) {
//             if (goodString.size() && goodString.back() != c && 
//                     tolower(goodString.back()) == tolower(c)) {
//                 goodString.pop_back();
//             } else {
//                 goodString += c;
//             }
//         }
//         return goodString;
//     }
// };

// stack
// time: O(n)
// space: O(1)

class Solution {
public:
    string makeGood(string s) {
        int end = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (end > 0 && abs(s[i] - s[end - 1]) == 32) {
                --end;
            } else {
                s[end] = s[i];
                ++end;
            }
        }
        return s.substr(0, end);
    }
};

// two pointers
// time: O(n)
// space: O(1)

