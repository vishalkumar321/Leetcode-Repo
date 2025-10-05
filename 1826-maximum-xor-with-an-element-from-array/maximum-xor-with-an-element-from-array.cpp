class Solution {
public:
    struct TrieNode {
        TrieNode* children[2];
        TrieNode() { children[0] = children[1] = nullptr; }
    };

    TrieNode* root;
    void insertTrie(int num) {
        TrieNode* node = root;

        for (int i = 31; i >= 0; i--) {
            int b = (num >> i) & 1;
            if (!node->children[b]) {
                node->children[b] = new TrieNode();
            }
            node = node->children[b];
        }
    }

    int maxXorWith(int num) {
        TrieNode* node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int b = (num >> i) & 1;
            int opp = 1 - b;
            if (node->children[opp]) {
                ans |= (1 << i);
                node = node->children[opp];
            } else if (node->children[b]) {
                node = node->children[b];
            } else {
                break;
            }
        }
        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int q = queries.size();

        vector<vector<int>> queries2 = queries;
        for (int i = 0; i < q; i++) {
            queries2[i].push_back(i);
        }

        sort(queries2.begin(), queries2.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        root = new TrieNode();
        vector<int> ans(q, -1);
        int idx = 0;

        for (auto qr : queries2) {
            int x = qr[0];
            int m = qr[1];
            int originalIdx = qr[2];

            while (idx < n && nums[idx] <= m) {
                insertTrie(nums[idx]);
                idx++;
            }

            if (idx > 0) {
                ans[originalIdx] = maxXorWith(x);
            } else {
                ans[originalIdx] = -1;
            }
        }
        return ans;
    }
};