class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    ++count;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
    
private:
    int offsets[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        grid[i][j] = '.';
        q.push(make_pair(i, j));
        while(!q.empty()) {
            int qSize = q.size();
            for(int k = 0; k < qSize; ++k) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                for(auto& offset: offsets) {
                    int ii = i + offset[0], jj = j + offset[1];
                    if(ii >= 0 && ii < grid.size() && jj >= 0 && jj < grid[0].size()) {
                        if(grid[ii][jj] == '1') {
                            q.push(make_pair(ii, jj));
                            grid[ii][jj] = '.';
                        }
                    }
                }
            }
        }
        return;
    }
};

// BFS
// Time: O(m * n)
// Space: O(min (m * n))
