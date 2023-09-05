bool compareNumber(int num1, int num2) {
    string num1Str = to_string(num1);
    string num2Str = to_string(num2);
    return num1Str + num2Str > num2Str + num1Str;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compareNumber);
        stringstream result;
        copy(nums.begin(), nums.end(), ostream_iterator<int>(result));
        string resultStr = result.str();
        return resultStr.erase(0, min(resultStr.find_first_not_of('0'), resultStr.size() - 1));
    }
};

// customized sort
// time O(n log n)
// space O(n)

