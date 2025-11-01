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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionBySize(mapMailNode[mail], i);
                }
            }
        }

        vector<vector<string>> merge(n);
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findParent(it.second);
            merge[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merge[i].size() == 0)
                continue;
            sort(merge[i].begin(), merge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : merge[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};