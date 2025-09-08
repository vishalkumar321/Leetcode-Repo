// BFS APPROACH
// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {

//         int n = graph.size();
//         vector<int> color(n, -1);

//         for (int i = 0; i < n; i++) {
//             if (color[i] == -1) {
//                 queue<int> q;
//                 q.push(i);
//                 color[i] = 0;

//                 while (!q.empty()) {
//                     int node = q.front();
//                     q.pop();

//                     for (int neighbour : graph[node]) {
//                         if (color[neighbour] == -1) {
//                             color[neighbour] = 1 - color[node];
//                             q.push(neighbour);
//                         } else if (color[neighbour] == color[node]) {
//                             return false;
//                         }
//                     }
//                 }
//             }
//         }
//         return true;
//     }
// };

//  DFS APPROACH
class Solution {
public:
    bool dfs(int node, int currentColor, vector<vector<int>>& graph,
             vector<int>& color) {
        color[node] = currentColor;

        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - currentColor, graph, color))
                    return false;
            } else if (color[neighbor] == currentColor) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                if (!dfs(i, 0, graph, color))
                    return false;
            }
        }
        return true;
    }
};
