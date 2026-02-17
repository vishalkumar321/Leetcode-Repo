class Solution {
public:
    double bfs(string src, string dest,
               unordered_map<string, vector<pair<string, double>>> graph) {
        if (graph.find(src) == graph.end() || graph.find(dest) == graph.end())
            return -1.0;

        if (src == dest)
            return 1.0;

        queue<pair<string, double>> q;
        unordered_set<string> visited;

        q.push({src, 1.0});
        visited.insert(src);

        while (!q.empty()) {
            auto [node, val] = q.front();
            q.pop();

            for (auto& it : graph[node]) {
                string next = it.first;
                double weight = it.second;

                if (visited.count(next))
                    continue;
                double newVal = val * weight;
                if (next == dest) {
                    return newVal;
                }
                visited.insert(next);
                q.push({next, newVal});
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;
        for (auto& q : queries) {
            string src = q[0];
            string dest = q[1];

            ans.push_back(bfs(src, dest, graph));
        }
        return ans;
    }
};