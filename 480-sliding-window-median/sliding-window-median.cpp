class Solution {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

    unordered_map<int, int> delayed;

    int smallSize = 0;
    int largeSize = 0;

    void pruneSmall() {
        while (!small.empty()) {
            int x = small.top();

            if (!delayed.count(x))
                break;

            delayed[x]--;

            if (delayed[x] == 0)
                delayed.erase(x);

            small.pop();
        }
    }

    void pruneLarge() {
        while (!large.empty()) {
            int x = large.top();

            if (!delayed.count(x))
                break;

            delayed[x]--;

            if (delayed[x] == 0)
                delayed.erase(x);

            large.pop();
        }
    }

    void balance() {

        if (smallSize > largeSize + 1) {

            large.push(small.top());
            small.pop();

            smallSize--;
            largeSize++;

            pruneSmall();
        }

        else if (smallSize < largeSize) {

            small.push(large.top());
            large.pop();

            largeSize--;
            smallSize++;

            pruneLarge();
        }
    }

    void insert(int num) {

        if (small.empty() || num <= small.top()) {
            small.push(num);
            smallSize++;
        }

        else {
            large.push(num);
            largeSize++;
        }

        balance();
    }

    void erase(int num) {

        delayed[num]++;

        if (num <= small.top()) {

            smallSize--;

            if (num == small.top())
                pruneSmall();
        }

        else {

            largeSize--;

            if (!large.empty() && num == large.top())
                pruneLarge();
        }

        balance();
    }

    double getMedian(int k) {

        if (k % 2)
            return small.top();

        return ((double)small.top() + (double)large.top()) / 2.0;
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;

        for (int i = 0; i < k; i++)
            insert(nums[i]);

        ans.push_back(getMedian(k));

        for (int i = k; i < nums.size(); i++) {

            erase(nums[i - k]);

            insert(nums[i]);

            ans.push_back(getMedian(k));
        }

        return ans;
    }
};