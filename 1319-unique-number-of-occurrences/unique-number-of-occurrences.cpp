class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> occur;
        unordered_set<int> duplicate;

        for (int i = 0; i < n; i++) {
            occur[arr[i]]++;
        }

        for (auto x : occur) {
            int ele = x.first;
            int cnt = x.second;

            duplicate.insert(cnt);
        }
        return duplicate.size() == occur.size();
    }
};