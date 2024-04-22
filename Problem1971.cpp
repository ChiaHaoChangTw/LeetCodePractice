class UnionFind {
public:
    UnionFind(int n): root(n), rank(n, 1) {
        iota(root.begin(), root.end(), 0);
    }
    int find(int x) {
        if (x != root[x]) {
            root[x] = find(root[x]);
        }
        return root[x];
    }
    void join(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                swap(rootx, rooty);
            }
            root[rootx] = rooty;
            rank[rooty] += rank[rootx];
        }
    }

private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        for (const auto &edge: edges) {
            uf.join(edge[0], edge[1]);
        }
        return uf.find(source) == uf.find(destination);
    }
};

// union find
// time: O(m * α(n))
// space: O(n)

