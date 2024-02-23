class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int minDist = INT_MAX;
        vector<vector<pair<int, int>>> g(n);
        unordered_map<int, int> nodeDistMap;
        for (const auto &f: flights) {
            g[f[0]].push_back({f[1], f[2]});
        }
        nodeDistMap[src] = 0;
        while (nodeDistMap.size() && k >= 0) {
            unordered_map<int, int> nodeDistMap_;
            for (const auto &[node, dist]: nodeDistMap) {
                for (const auto &[next, d]: g[node]) {
                    int currDist = dist + d;
                    if (currDist > minDist) {
                        continue;
                    }
                    if (!nodeDistMap_.count(next)) {
                        nodeDistMap_[next] = currDist;
                    } else {
                        nodeDistMap_[next] = min(currDist, nodeDistMap_[next]);
                    }
                    if (next == dst) {
                        minDist = min(minDist, nodeDistMap_[next]);
                    }
                }
            }
            nodeDistMap = nodeDistMap_;
            --k;
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};
