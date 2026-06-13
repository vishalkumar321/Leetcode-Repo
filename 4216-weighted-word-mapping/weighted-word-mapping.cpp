class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (auto& it : words) {
            int sum = 0;
            for (auto& i : it) {
                sum += weights[i - 'a'];
            }
            sum = sum % 26;
            ans += ('z' - sum);
        }
        return ans;
    }
};