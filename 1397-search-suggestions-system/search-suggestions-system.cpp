class TrieNode {
public:
    TrieNode* child[26];
    vector<string> sugg;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->child[idx]) {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];

            if (node->sugg.size() < 3) {
                node->sugg.push_back(word);
            }
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        sort(products.begin(), products.end());

        for (string& p : products) {
            insert(p);
        }

        vector<vector<string>> ans;
        TrieNode* node = root;

        for (char c : searchWord) {
            if (node) {
                node = node->child[c - 'a'];
            }

            if (node) {
                ans.push_back(node->sugg);
            } else {
                ans.push_back({});
            }
        }
        return ans;
    }
};