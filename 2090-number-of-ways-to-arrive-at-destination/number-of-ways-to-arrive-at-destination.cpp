class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        int MOD = 1e9 + 7;
        vector<vector<pair<int, long long>>> adj(n);
        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            long long wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (wt > dist[node])
                continue;
            for (auto it : adj[node]) {
                int adjNode = it.first;
                long long edgeWgt = it.second;

                if (wt + edgeWgt < dist[adjNode]) {
                    dist[adjNode] = wt + edgeWgt;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                } 
                else if (wt + edgeWgt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1] % MOD;
    }
};