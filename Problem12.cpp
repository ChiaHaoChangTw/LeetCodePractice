class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        vector<int> values = {1000, 500, 100, 50, 10, 5, 1}; 
        vector<char> symbols = {'M', 'D', 'C', 'L', 'X', 'V', 'I'}; 

        for(int i = 0; i < values.size() && num; ++i) {
            int count = num / values[i];
            num %= values[i];

            if(count == 4) {
                result += (string(1, symbols[i]) + string(1, symbols[i - 1]));
            } else if(count == 1 && i + 1 < values.size() && num / values[i + 1] == 4) {
                result += (string(1, symbols[i + 1]) + string(1, symbols[i - 1]));
                num %= values[i + 1];
            } else {
                result += string(count, symbols[i]);
            }
        }

        return result;
    }
};

