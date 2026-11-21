class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);

        stack<tuple<int, bool, int>> st;
        st.push({0, false, -1});

        while (!st.empty()) {
            auto [node, exit, prev] = st.top();
            st.pop();

            int ch = s[node] - 'a';

            if (!exit) {
                prev = last[ch];

                if (node != 0 && prev != -1) {
                    parent[node] = prev;
                }

                last[ch] = node;

                st.push({node, true, prev});

                for (int i = adj[node].size() - 1; i >= 0; i--) {
                    st.push({adj[node][i], false, -1});
                }
            } else {
                last[ch] = prev;
            }
        }

        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[parent[i]].push_back(i);
        }

        vector<int> order;
        stack<int> dfs;

        dfs.push(0);

        while (!dfs.empty()) {
            int node = dfs.top();
            dfs.pop();

            order.push_back(node);

            for (int child : newAdj[node]) {
                dfs.push(child);
            }
        }

        vector<int> ans(n, 1);

        for (int i = order.size() - 1; i >= 0; i--) {
            int node = order[i];

            for (int child : newAdj[node]) {
                ans[node] += ans[child];
            }
        }
        return ans;
    }
};