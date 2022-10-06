class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double minCost = DBL_MAX;
        int sumQuality = 0;
        vector<pair<double, int>> ratios;
        priority_queue<int> qualities;
        
        for(int i = 0; i < quality.size(); ++i) {
            ratios.push_back(make_pair((wage[i] * 1.0) / quality[i], i));
        }
        sort(ratios.begin(), ratios.end());
        
        for(auto& ratio: ratios) {
            double r = ratio.first;
            int worker = ratio.second;
            qualities.push(quality[worker]);
            sumQuality += quality[worker];
            if(qualities.size() > k) {
                sumQuality -= qualities.top();
                qualities.pop();
            }
            if(qualities.size() == k) {
                double currCost = sumQuality * r;
                minCost = min(minCost, currCost);
            }
        }
        
        return minCost;
    }
};

