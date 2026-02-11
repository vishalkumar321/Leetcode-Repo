class SegmentTree {
public:
    int n;
    vector<int> mn, mx, lazy;

    SegmentTree(const vector<int>& a) {
        n = a.size();
        mn.resize(4 * n);
        mx.resize(4 * n);
        lazy.assign(4 * n, 0);
        build(a, 1, 0, n - 1);
    }

    void build(const vector<int>& a, int node, int l, int r) {
        if (l == r) {
            mn[node] = mx[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, node * 2, l, mid);
        build(a, node * 2 + 1, mid + 1, r);
        pull(node);
    }

    void pull(int node) {
        mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
        mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
    }

    void push(int node) {
        if (lazy[node] != 0) {
            apply(node * 2, lazy[node]);
            apply(node * 2 + 1, lazy[node]);
            lazy[node] = 0;
        }
    }

    void apply(int node, int val) {
        mn[node] += val;
        mx[node] += val;
        lazy[node] += val;
    }

    void update(int L, int R, int val, int node, int l, int r) {
        if (L <= l && r <= R) {
            apply(node, val);
            return;
        }
        push(node);
        int mid = (l + r) / 2;
        if (L <= mid) update(L, R, val, node * 2, l, mid);
        if (R > mid) update(L, R, val, node * 2 + 1, mid + 1, r);
        pull(node);
    }

    int query(int L, int R, int val, int node, int l, int r) {
        if (mn[node] > val || mx[node] < val) return -1;
        if (l == r) return l;
        push(node);
        int mid = (l + r) / 2;
        if (R > mid) {
            int right = query(L, R, val, node * 2 + 1, mid + 1, r);
            if (right != -1) return right;
        }
        if (L <= mid) return query(L, R, val, node * 2, l, mid);
        return -1;
    }

    void add(int l, int r, int val) {
        if (l > r) return;
        update(l, r, val, 1, 0, n - 1);
    }

    int findLast(int start) {
        if (start >= n) return -1;
        return query(start, n - 1, 0, 1, 0, n - 1);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        map<int, queue<int>> occ;
        auto sgn = [&](int x) { return x % 2 == 0 ? 1 : -1; };

        vector<int> prefix(n);
        prefix[0] = sgn(nums[0]);
        occ[nums[0]].push(0);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if (occ[nums[i]].empty())
                prefix[i] += sgn(nums[i]);
            occ[nums[i]].push(i);
        }

        SegmentTree seg(prefix);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int pos = seg.findLast(i + ans);
            if (pos != -1)
                ans = max(ans, pos - i + 1);

            occ[nums[i]].pop();
            int nextPos = n;
            if (!occ[nums[i]].empty())
                nextPos = occ[nums[i]].front();

            seg.add(i, nextPos - 1, -sgn(nums[i]));
        }

        return ans;
    }
};
