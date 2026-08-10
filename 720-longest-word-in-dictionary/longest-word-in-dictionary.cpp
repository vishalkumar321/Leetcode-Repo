class Solution {
public:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;

            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root = new Node();

    void insert(string& word) {

        Node* curr = root;

        for (char c : word) {

            int index = c - 'a';

            if (curr->child[index] == nullptr) {
                curr->child[index] = new Node();
            }

            curr = curr->child[index];
        }

        curr->isEnd = true;
    }

    string ans = "";

    void dfs(Node* curr, string& current) {

        if (current.length() > ans.length() ||
            (current.length() == ans.length() && current < ans)) {
            ans = current;
        }

        for (int i = 0; i < 26; i++) {

            if (curr->child[i] != nullptr && curr->child[i]->isEnd) {

                current.push_back('a' + i);

                dfs(curr->child[i], current);

                current.pop_back();
            }
        }
    }

    string longestWord(vector<string>& words) {

        for (string& word : words) {
            insert(word);
        }

        string current = "";

        dfs(root, current);

        return ans;
    }
};