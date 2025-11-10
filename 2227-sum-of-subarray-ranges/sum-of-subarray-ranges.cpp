class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> s1, s2;
        vector<int> next(n), prev(n);

        for (int i = 0; i < n; i++) {
            while (!s1.empty() && arr[s1.top()] > arr[i]) {
                s1.pop();
            }
            prev[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) {
                s2.pop();
            }
            next[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            res += (long long)arr[i] * left * right;
        }
        return res;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        stack<int> s1, s2;
        vector<int> prev(n), next(n);

        for (int i = 0; i < n; i++) {
            while (!s1.empty() && arr[s1.top()] < arr[i]) {
                s1.pop();
            }
            prev[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && arr[s2.top()] <= arr[i]) {
                s2.pop();
            }
            next[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            res += (long long)arr[i] * left * right;
        }
        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
