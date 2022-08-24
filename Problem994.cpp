class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int numFresh = 0;
        queue<pair<int, int>> bfsTodo;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0 ; j < grid[i].size(); ++j) {
                if(grid[i][j] == 1) {
                    ++numFresh;
                }
                if(grid[i][j] == 2) {
                    bfsTodo.push(make_pair(i, j));
                }
            }
        }
        
        int minutes = 0;
        int numChanges = 0;
        vector<vector<int>> offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!bfsTodo.empty()) {
            int todoSize = bfsTodo.size();
            for(int k = 0; k < todoSize; ++k) {
                pair<int, int> todo = bfsTodo.front();
                bfsTodo.pop();
                for(auto& offset: offsets) {
                    int ii = todo.first + offset[0];
                    int jj = todo.second + offset[1];
                    if(ii >= 0 && ii < grid.size() && jj >= 0 && jj < grid[0].size()) {
                        if(grid[ii][jj] == 1) {
                            grid[ii][jj] = 2;
                            bfsTodo.push(make_pair(ii, jj));
                            ++numChanges;
                        }
                    }
                }
            }
            ++minutes;
        }
        
        return (numChanges == numFresh) ? ((minutes > 0) ? minutes - 1 : 0) : (-1);
    }
};


