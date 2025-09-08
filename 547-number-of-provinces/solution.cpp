// DFS APPROACH
// class Solution {
// public:
//     void DFS(int node,vector<vector<int>>& isConnected, vector<bool>&
//     visited){
//         visited[node] =true;

//         for(int j=0; j<isConnected.size(); j++){
//             if(isConnected[node][j] == 1 && !visited[j]){
//                 DFS(j, isConnected, visited);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {

//         int n= isConnected.size();
//         vector<bool>visited(n,0);
//         int provinces = 0;

//         for(int i=0; i<n; i++){
//             if(!visited[i]){
//                 DFS(i, isConnected, visited);
//                 provinces++;
//             }
//         }
//         return provinces;
//     }
// };

// BFS APPROACH

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<bool> visited(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < n; j++) {
                        if (isConnected[node][j] == 1 && !visited[j]) {
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }
};