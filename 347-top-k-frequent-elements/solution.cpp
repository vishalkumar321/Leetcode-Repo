class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for (int num : nums) {
            freqMap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            p;

        for (auto& [num, freq] : freqMap) {
            p.push({freq, num});
            if (p.size() > k) {
                p.pop();
            }
        }

        vector<int> result;
        while (!p.empty()) {
            result.push_back(p.top().second);
            p.pop();
        }
        return result;
    }
};