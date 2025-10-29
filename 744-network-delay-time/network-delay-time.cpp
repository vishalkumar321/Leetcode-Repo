class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> time(n + 1, 1e9);
        time[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWgt = it.second;

                if (dist + edgeWgt < time[adjNode]) {
                    time[adjNode] = dist + edgeWgt;
                    pq.push({time[adjNode], adjNode});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (time[i] == 1e9)
                return -1;
            ans = max(ans, time[i]);
        }
        return ans;
    }
};