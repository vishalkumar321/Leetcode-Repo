class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target)
            return 0;

        int n = routes.size();
        unordered_map<int, vector<int>> adjList;

        for (int i = 0; i < n; i++) {
            for (auto& it : routes[i]) {
                adjList[it].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> visited;

        for (auto& it : adjList[source]) {
            q.push(it);
            visited.insert(it);
        }

        int busCnt = 1;
        while (!q.empty()) {
            int len = q.size();

            for (int i = 0; i < len; i++) {
                int route = q.front();
                q.pop();

                for (auto it : routes[route]) {
                    if (it == target)
                        return busCnt;

                    for (auto& next : adjList[it]) {
                        if (!visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            busCnt++;
        }
        return -1;
    }
};