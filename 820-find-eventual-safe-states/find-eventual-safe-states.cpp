class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> outDeg(n);

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (auto& it : graph[i]) {
                adj[it].push_back(i);
                outDeg[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!outDeg[i]){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto& it : adj[node]){
                outDeg[it]--;
                if(outDeg[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};