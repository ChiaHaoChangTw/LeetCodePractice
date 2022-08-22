class Solution {
public:
    bool differByOne(vector<string>& dict) {
        int mod = 1000000007;
        vector<int> hashVals(dict.size());
        
        for(int i = 0; i < dict.size(); ++i) {
            for(int j = 0; j < dict[i].size(); ++j) {
                hashVals[i] = ((26l * hashVals[i]) + (dict[i][j] - 'a')) % mod;
            }
        }
        
        int mul = 1;
        for(int j = dict[0].size() - 1; j >= 0; --j) {
            unordered_map<int, vector<int>> removeOneMap;
            
            for(int i = 0; i < dict.size(); ++i) {
                int newHashVal = (mod + hashVals[i] - ((long)(dict[i][j] - 'a') * mul % mod)) % mod;
                
                auto it = removeOneMap.find(newHashVal);
                if(it != removeOneMap.end()) {
                    for(auto ii: it->second) {
                        if(equal(dict[i].begin(), dict[i].begin() + j, dict[ii].begin()) &&
                           equal(dict[i].begin() + j + 1, dict[i].end(), dict[ii].begin() + j + 1)) {
                            return true;
                        }
                    }
                }
                
                removeOneMap[newHashVal].push_back(i);
            }
            
            mul = 26l * mul % mod;
        }
        
        return false;
    }
};

// hash
// Rabin-Karp
