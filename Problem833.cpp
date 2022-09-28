class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> revIndices;
        for(int i = 0; i < indices.size(); ++i) {
            revIndices.push_back(make_pair(indices[i], i));
        }
        sort(revIndices.begin(), revIndices.end(), 
             [] (pair<int, int>& p1, pair<int, int>& p2) {return p1.first > p2.first;});
        for(auto& indPair: revIndices) {
            int i = indPair.first;
            int ii = indPair.second;
            string source = sources[ii], target = targets[ii];
            if(s.substr(i, source.size()) == source) {
                s = s.substr(0, i) + target + s.substr(i + source.size());
            }
        }
        return s;
    }
};
