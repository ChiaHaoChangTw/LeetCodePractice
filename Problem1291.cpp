class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> seqDigits;
        string seqStr = "123456789";
        int lowLen = to_string(low).size();
        int highLen = to_string(high).size();
        for (int len = lowLen; len <= highLen; ++len) {
            for (int start = 0; start + len <= 9; ++start) {
                int seqNum = stoi(seqStr.substr(start, len));
                if (seqNum >= low && seqNum <= high) {
                    seqDigits.push_back(seqNum);
                }
            }
        }
        return seqDigits;
    }
};

// sliding window
// time: O(1)
// space: O(1)

