class DisjointSet {
public:
    vector<int> parent, rank, size;
    // Constructor: Initialize parent, rank, and size
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find parent with path compression
    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    // Check if two nodes belong to the same set
    bool find(int u, int v) { return findParent(u) == findParent(v); }

    // Union by Rank
    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;

        if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else if (rank[pv] > rank[pu]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    // Union by Size
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;

                int delRow[] = {-1, 0, 1, 0};
                int delCol[] = {0, 1, 0, -1};

                for (int index = 0; index < 4; index++) {
                    int nrow = row + delRow[index];
                    int ncol = col + delCol[index];

                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = nrow * n + ncol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int maxi = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;

                int delRow[] = {-1, 0, 1, 0};
                int delCol[] = {0, 1, 0, -1};

                set<int> components;
                for (int index = 0; index < 4; index++) {
                    int nrow = row + delRow[index];
                    int ncol = col + delCol[index];

                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        components.insert(ds.findParent(nrow * n + ncol));
                    }
                }
                int totalSize = 0;
                for (auto it : components) {
                    totalSize += ds.size[it];
                }
                maxi = max(maxi, totalSize + 1);
            }
        }
        
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            maxi = max(maxi, ds.size[ds.findParent(cellNo)]);
        }
        return maxi;
    }
};