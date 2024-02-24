class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> knowSecret;
        vector<bool> know(n , false);
        map<int, vector<pair<int, int>>> timeMeetingsMap; 
        know[0] = true;
        know[firstPerson] = true;
        sort(meetings.begin(), meetings.end(), 
             [](const auto &m1, const auto &m2){return m1[2] < m2[2];});
        for (const auto &meeting: meetings) {
            timeMeetingsMap[meeting[2]].push_back({meeting[0], meeting[1]});
        }
        for (const auto &[_, ms]: timeMeetingsMap) {
            unordered_map<int, vector<int>> g;
            unordered_set<int> starts;
            queue<int> bfsQueue;
            for (const auto &[u, v]: ms) {
                g[u].push_back(v);
                g[v].push_back(u);
                if (know[u]) {
                    starts.insert(u);
                }
                if (know[v]) {
                    starts.insert(v);
                }
            }
            for (const auto &start: starts) {
                bfsQueue.push(start);
            }
            while (!bfsQueue.empty()) {
                int curr = bfsQueue.front();
                bfsQueue.pop();
                for (const auto &next: g[curr]) {
                    if (!know[next]) {
                        bfsQueue.push(next);
                        know[next] = true;
                    }
                }
            }
        }
        cout << "test" << endl;
        for (int i = 0; i < know.size(); ++i) {
            if (know[i]) {
                knowSecret.push_back(i);
            }
        }
        return knowSecret;
    }
};
