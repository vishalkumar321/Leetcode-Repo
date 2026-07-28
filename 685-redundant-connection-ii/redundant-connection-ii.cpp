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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        // STEP 1: Detect a node having two parents
        vector<int> incomingParent(n + 1, 0);

        vector<int> firstEdge;
        vector<int> secondEdge;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (incomingParent[v] == 0) {
                incomingParent[v] = u;
            } else {
                firstEdge = {incomingParent[v], v};
                secondEdge = {u, v};
                break;
            }
        }

        // STEP 2: Run DSU, skipping secondEdge
        DisjointSet ds(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (!secondEdge.empty() && edge == secondEdge)
                continue;

            if (ds.find(u, v)) {

                // Two-parent problem + cycle
                if (!firstEdge.empty())
                    return firstEdge;

                // Only cycle, same as 684
                return edge;
            }

            ds.unionBySize(u, v);
        }

        // No cycle after removing secondEdge
        return secondEdge;
    }
};