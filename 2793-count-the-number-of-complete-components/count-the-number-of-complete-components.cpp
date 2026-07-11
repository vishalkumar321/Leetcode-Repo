class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodes = 0;
                int edgeCount = 0;

                visited[i] = true;
                q.push(i);

                while (!q.empty()) {
                    auto node = q.front();
                    q.pop();

                    nodes++;
                    edgeCount += adj[node].size();

                    for (auto it : adj[node]) {
                        if (!visited[it]) {
                            visited[it] = true;
                            q.push(it);
                        }
                    }
                }
                edgeCount /= 2;
                if (edgeCount == nodes * (nodes - 1) / 2) {
                    comp++;
                }
            }
        }
        return comp;
    }
};