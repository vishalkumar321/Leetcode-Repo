class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);

        dist[src] = 0;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto nodes = q.front();
            q.pop();
            int steps = nodes.first;
            int node = nodes.second.first;
            int cost = nodes.second.second;

            if (steps > k)
                continue;
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWgt = it.second;

                if (cost + edgeWgt < dist[adjNode] && steps <= k) {
                    dist[adjNode] = cost + edgeWgt;
                    q.push({steps + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};