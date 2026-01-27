class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int cost = edge[2];
            graph[from].push_back({to, cost});
            graph[to].push_back({from, 2 * cost});
        }

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            if (node == n - 1) {
                return dist[node];
            }

            if (visited[node]) {
                continue;
            }

            visited[node] = true;

            for (auto& e : graph[node]) {
                int next = e.first;
                int cost = e.second;

                if (dist[node] + cost < dist[next]) {
                    dist[next] = dist[node] + cost;
                    pq.push({dist[next], next});
                }
            }
        }

        return -1;
    }
};
