class Solution {
public:
    int buildWall(int height, int width, vector<int>& bricks) {
        vector<int> wallMasks = dfsWidth(0, width, bricks, 0, vector<int>() = {});
        vector<vector<int>> ids(wallMasks.size() + 1);
        for(int i = 0; i < wallMasks.size(); ++i) {
            for(int j = 0; j < wallMasks.size(); ++j) {
                if(i == 0) {
                    ids[0].push_back(j + 1);
                }
                if((wallMasks[i] & wallMasks[j]) == 0) {
                    ids[i + 1].push_back(j + 1);
                }
            }
        }
        return dfsHeight(height, 0, ids);
    }
    
private:
    int dp[101][1024] = {};
    
    int dfsHeight(int height, int i, vector<vector<int>>& ids) {
        if(height == 0) {
            return 1;
        }
        if(dp[height][i] == 0) {
            for(int j: ids[i]) {
                dp[height][i] = (dp[height][i] + dfsHeight(height - 1, j, ids)) % 1000000007;
            }
        }
        return dp[height][i];
    }
    
    vector<int> dfsWidth(int w, int width, vector<int>& bricks, int mask, vector<int>& masks) {
        if(w == width) {
            masks.push_back(mask);
        }
        else {
            if(w) {
                mask += (1 << (w - 1));
            }
            for(auto& brick: bricks) {
                if(w + brick <= width) {
                    dfsWidth(w + brick, width, bricks, mask, masks);
                }
            }
        }
        return masks;
    }
};

// dfs
// dynamic programming
