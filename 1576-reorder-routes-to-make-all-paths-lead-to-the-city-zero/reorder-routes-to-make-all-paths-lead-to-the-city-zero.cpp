class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& c : connections) {
            adj[c[0]].push_back({c[1], 1});
            adj[c[1]].push_back({c[0], 0});
        }

        vector<bool> visited(n);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int ans = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& [next, cost] : adj[node]) {
                if (!visited[next]) {
                    ans += cost;
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        return ans;
    }
};