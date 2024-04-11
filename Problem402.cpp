class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        for (int i = 0; i < num.size(); ++i) {
            while (!result.empty() && result.back() > num[i] && k > 0) {
                result.pop_back();
                --k;
            }
            result += num[i];
        }
        while (k > 0) {
            result.pop_back();
            --k;
        }
        result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
        return result.empty() ? "0" : result;
    }
};

// stack
// time: O(n)
// space: O(n)

