class NumArray {
public:
    vector<int> seg;
    int n;

    void buildTree(vector<int>& nums, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildTree(nums, 2 * idx + 1, l, mid);
        buildTree(nums, 2 * idx + 2, mid + 1, r);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void updateHelper(int idx, int l, int r, int index, int val) {

        if (l == r) {
            seg[idx] = val;
            return;
        }
        int mid = l + (r - l) / 2;

        if (index <= mid) {
            updateHelper(2 * idx + 1, l, mid, index, val);
        } else {
            updateHelper(2 * idx + 2, mid + 1, r, index, val);
        }

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return 0;
        }

        if (start >= left && end <= right) {
            return seg[idx];
        }

        int mid = start + (end - start) / 2;
        return query(2 * idx + 1, start, mid, left, right) +
               query(2 * idx + 2, mid + 1, end, left, right);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        buildTree(nums, 0, 0, n - 1);
    }

    void update(int index, int val) {
        updateHelper(0, 0, n - 1, index, val); 
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */