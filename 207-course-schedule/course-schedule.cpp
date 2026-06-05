class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses);
        vector<vector<int>> adj(numCourses);

        for (auto& it : prerequisites) {
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
            inDeg[v]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!inDeg[i]) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto& it : adj[node]) {
                inDeg[it]--;
                if (inDeg[it] == 0) {
                    q.push(it);
                }
            }
        }
        return numCourses == count;
    }
};