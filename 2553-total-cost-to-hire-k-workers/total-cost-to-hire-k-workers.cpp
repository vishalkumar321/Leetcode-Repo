class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        int n = costs.size();
        long long totalSum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            leftHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            rightHeap;

        int left = 0;
        int right = n - 1;

        for (int i = 0; i < candidates && left <= right; i++) {
            leftHeap.push({costs[left], left});
            left++;
        }
        for (int i = 0; i < candidates && left <= right; i++) {
            rightHeap.push({costs[right], right});
            right--;
        }

        while (k--) {
            if (rightHeap.empty() ||
                (!leftHeap.empty() && leftHeap.top() <= rightHeap.top())) {
                auto [cost, idx] = leftHeap.top();
                leftHeap.pop();
                totalSum += cost;

                if (left <= right) {
                    leftHeap.push({costs[left], left});
                    left++;
                }
            } else {
                auto [cost, idx] = rightHeap.top();
                rightHeap.pop();
                totalSum += cost;

                if (left <= right) {
                    rightHeap.push({costs[right], right});
                    right--;
                }
            }
        }
        return totalSum;
    }
};