class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator > 0 && denominator < 0) {
            return '-' + fractionToDecimal(-numerator, denominator);
        }
        if (numerator < 0 && denominator > 0) {
            return '-' + fractionToDecimal(numerator, -denominator);
        }

        long numeratorLong = long(numerator);
        long denominatorLong = long(denominator);
        string intStr = to_string(numeratorLong / denominatorLong);
        long remainder = numeratorLong % denominatorLong;
        if (remainder == 0) {
            return intStr;
        }

        unordered_map<long, int> seenRemainderMap;
        string decimalStr = "";
        remainder *= 10;
        seenRemainderMap[remainder] = decimalStr.size();

        while (remainder) {
            decimalStr += to_string(remainder / denominatorLong);
            remainder %= denominatorLong;
            remainder *= 10;
            if (seenRemainderMap.find(remainder) != seenRemainderMap.end()) {
                decimalStr = decimalStr.substr(0, seenRemainderMap[remainder]) + '(' 
                                + decimalStr.substr(seenRemainderMap[remainder]) + ')';
                break;
            }
            seenRemainderMap[remainder] = decimalStr.size();
        }

        return intStr + '.' + decimalStr;
    }
};

// hash
// edge cases
// time O(n)
// space O(n)

