class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> InDeg(numCourses, 0);

        for (auto& it : prerequisites) {
            int u = it[1], v = it[0];
            adj[u].push_back(v);
            InDeg[v]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!InDeg[i])
                q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbour : adj[node]) {
                InDeg[neighbour]--;
                if (InDeg[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        return count == numCourses;
    }
};