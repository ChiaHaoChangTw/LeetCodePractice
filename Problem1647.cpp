class Solution {
public:
    int minDeletions(string s) {
        vector<int> countVec(26, 0);
        for(auto& c: s) {
            ++countVec[c - 'a'];
        }
        
        sort(countVec.begin(), countVec.end(), greater<int>());
        
        int result = 0;
        for(int i = 1; i < countVec.size(); ++i) {
            if(countVec[i] != 0 && countVec[i] >= countVec[i - 1]) {
                int minus = (countVec[i - 1] != 0) ? 
                    (countVec[i] - countVec[i - 1] + 1) : (countVec[i] - countVec[i - 1]);
                result += minus;
                countVec[i] -= minus;
            }
        }
        
        return result;
    }
};
