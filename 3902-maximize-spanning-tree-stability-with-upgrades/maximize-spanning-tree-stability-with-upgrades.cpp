class Solution {
public:
    struct Edge {
        int u, v, w, type;
    };

    class DSU {
    public:
        vector<int> parent;

        DSU(vector<int> p) {
            parent = p;
        }

        int findParent(int x) {
            if (parent[x] == x) return x;
            return parent[x] = findParent(parent[x]);
        }

        void unite(int a, int b) {
            int pa = findParent(a);
            int pb = findParent(b);
            if (pa != pb) parent[pa] = pb;
        }
    };

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        const int MAX_STABILITY = 200000;
        int ans = -1;

        if (edges.size() < n - 1) return -1;

        vector<Edge> allEdges;
        for (auto &e : edges) {
            allEdges.push_back({e[0], e[1], e[2], e[3]});
        }

        vector<Edge> mustEdges;
        vector<Edge> optionalEdges;

        for (auto &e : allEdges) {
            if (e.type == 1) mustEdges.push_back(e);
            else optionalEdges.push_back(e);
        }

        if (mustEdges.size() > n - 1) return -1;

        sort(optionalEdges.begin(), optionalEdges.end(),
             [](Edge &a, Edge &b) { return b.w < a.w; });

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        DSU base(parent);

        int selected = 0;
        int minMust = MAX_STABILITY;

        for (auto &e : mustEdges) {
            if (base.findParent(e.u) == base.findParent(e.v) || selected == n - 1)
                return -1;

            base.unite(e.u, e.v);
            selected++;
            minMust = min(minMust, e.w);
        }

        int left = 0;
        int right = minMust;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            DSU dsu(base.parent);

            int used = selected;
            int doubled = 0;

            for (auto &e : optionalEdges) {
                if (dsu.findParent(e.u) == dsu.findParent(e.v)) continue;

                if (e.w >= mid) {
                    dsu.unite(e.u, e.v);
                    used++;
                } 
                else if (doubled < k && e.w * 2 >= mid) {
                    doubled++;
                    dsu.unite(e.u, e.v);
                    used++;
                } 
                else {
                    break;
                }

                if (used == n - 1) break;
            }

            if (used != n - 1) {
                right = mid - 1;
            } else {
                ans = mid;
                left = mid;
            }
        }

        return ans;
    }
};