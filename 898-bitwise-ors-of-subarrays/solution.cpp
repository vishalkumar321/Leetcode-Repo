class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> prev;

        for (int num : arr) {
            unordered_set<int> curr;
            curr.insert(num);
            for (int val : prev) {
                curr.insert(num | val);
            }
            prev = curr;
            for (int val : curr) {
                ans.insert(val);
            }
        }
        return ans.size();
    }
};