class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visiting(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0, visiting)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    vector<vector<int>> offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool dfs(const vector<vector<char>> &board, const string &word, 
             int i, int j, int len, vector<vector<bool>> &visiting) {
        if (len >= word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        if (visiting[i][j] || board[i][j] != word[len]) {
            return false;
        }
        visiting[i][j] = true;
        for (const auto &offset: offsets) {
            if (dfs(board, word, i + offset[0], j + offset[1], len + 1, visiting)) {
                return true;
            }
        }
        visiting[i][j] = false;
        return false;
    }
};

// backtracking
// time: O(m * n * 3 ^ l)
// space: O(m * n)

