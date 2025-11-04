class Solution {
public:
    int getXSum(unordered_map<int, int> freqMap, int x) {
        vector<pair<int, int>> vec(freqMap.begin(), freqMap.end());

        sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        });

        int sum = 0, count = 0;
        for (auto& p : vec) {
            sum += p.first * p.second;
            count++;
            if (count == x)
                break;
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> freq;

        for (int i = 0; i < k; i++)
            freq[nums[i]]++;

        ans.push_back(getXSum(freq, x));

        for (int i = k; i < n; i++) {
            freq[nums[i - k]]--;
            if (freq[nums[i - k]] == 0)
                freq.erase(nums[i - k]);
            freq[nums[i]]++;
            ans.push_back(getXSum(freq, x));
        }

        return ans;
    }
};
