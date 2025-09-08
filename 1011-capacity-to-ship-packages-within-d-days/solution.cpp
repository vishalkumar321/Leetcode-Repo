class Solution {
public:
    int possible(vector<int>& weights, int days, int capacity) {
        int currday = 1;
        int currweight = 0;

        for (int w : weights) {
            if (currweight + w > capacity) {
                currday++;
                currweight = 0;
            }
            currweight += w;
            if (currday > days)
                return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(weights, days, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};