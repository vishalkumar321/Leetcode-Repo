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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        DisjointSet ds(n);

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                ds.unionBySize(i, i - 1);
            }
        }

        vector<bool> ans(queries.size());

        int idx = 0;
        for (auto& it : queries) {
            int u = it[0];
            int v = it[1];

            if (ds.findParent(u) == ds.findParent(v)) {
                ans[idx] = true;
            } else {
                ans[idx] = false;
            }
            idx++;
        }
        return ans;
    }
};