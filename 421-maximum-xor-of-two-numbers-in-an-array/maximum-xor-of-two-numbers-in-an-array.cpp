class Solution {
public:
    struct TrieNode {
        TrieNode* children[2];
        TrieNode() {
            children[0] = children[1] = nullptr;
        }
    };
    
    TrieNode* root;
    
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {   
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opp = 1 - bit;  
            if (node->children[opp]) {
                maxXor |= (1 << i);
                node = node->children[opp];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for (int num : nums) {
            insert(num);
        }
        
        int result = 0;
        for (int num : nums) {
            result = max(result, findMaxXOR(num));
        }
        return result;
    }
};
