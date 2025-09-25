class Solution {
public:
    unordered_map<string, int> memo;
    unordered_set<string> wordList;

    int solve(string word) {
        if (memo.count(word))
            return memo[word];

        int ans = 1;
        for (int i = 0; i < word.size(); i++) {
            string pred = word.substr(0, i) + word.substr(i + 1);

            if (wordList.count(pred)) {
                ans = max(ans, 1 + solve(pred));
            }
        }
        return memo[word] = ans;
    }

    int longestStrChain(vector<string>& words) {
        for (auto& w : words) {
            wordList.insert(w);
        }
        int best = 1;
        for (int i = 0; i < words.size(); i++) {
            best = max(best, solve(words[i]));
        }
        return best;
    }
};