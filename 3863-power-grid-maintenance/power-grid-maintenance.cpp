class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void rankUnion(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return;

        if (rank[pa] < rank[pb])
            parent[pa] = pb;
        else if (rank[pb] < rank[pa])
            parent[pb] = pa;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {

        DSU dsu(c + 1);

        for (auto& p : connections)
            dsu.rankUnion(p[0], p[1]);

        vector<bool> online(c + 1, true);
        vector<int> offlineCount(c + 1, 0);
        unordered_map<int, int> minOnline;

        for (auto& q : queries) {
            if (q[0] == 2) {
                online[q[1]] = false;
                offlineCount[q[1]]++;
            }
        }

        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            if (!minOnline.count(root))
                minOnline[root] = -1;
            if (online[i]) {
                if (minOnline[root] == -1 || i < minOnline[root])
                    minOnline[root] = i;
            }
        }

        vector<int> ans;

        for (int i = queries.size() - 1; i >= 0; i--) {
            int op = queries[i][0];
            int x = queries[i][1];
            int root = dsu.find(x);
            int best = minOnline[root];

            if (op == 1) {
                if (online[x])
                    ans.push_back(x);
                else
                    ans.push_back(best);
            } else {
                if (offlineCount[x] > 1) {
                    offlineCount[x]--;
                } else {
                    offlineCount[x]--;
                    online[x] = true;
                    if (best == -1 || x < best)
                        minOnline[root] = x;
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
