class Solution {
public:
    long long getSum(vector<int>& arr, int val) {
        long long sum = 0;

        for (int x : arr) {
            sum += min(x, val);
        }
        return sum;
    }

    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();

        int low = 1;
        int high = *max_element(arr.begin(), arr.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (getSum(arr, mid) >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long sum1 = getSum(arr, low);
        long long sum2 = getSum(arr, low - 1);

        if (abs(sum1 - target) < abs(sum2 - target)) {
            return low;
        }
        return low - 1;
    }
};