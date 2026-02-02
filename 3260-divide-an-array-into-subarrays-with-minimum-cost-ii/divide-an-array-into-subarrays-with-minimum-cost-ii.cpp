class Container {
public:
    int k;
    long long sum;
    int leftSize;

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    unordered_map<int, int> delayed;

    Container(int k) : k(k), sum(0), leftSize(0) {}

    void pruneLeft() {
        while (!left.empty()) {
            int x = left.top();
            if (delayed.count(x)) {
                if (--delayed[x] == 0)
                    delayed.erase(x);
                left.pop();
            } else
                break;
        }
    }

    void pruneRight() {
        while (!right.empty()) {
            int x = right.top();
            if (delayed.count(x)) {
                if (--delayed[x] == 0)
                    delayed.erase(x);
                right.pop();
            } else
                break;
        }
    }

    void balance() {
        pruneLeft();
        pruneRight();

        while (leftSize > k) {
            int x = left.top();
            left.pop();
            sum -= x;
            leftSize--;
            right.push(x);
        }

        while (leftSize < k && !right.empty()) {
            int x = right.top();
            right.pop();
            sum += x;
            left.push(x);
            leftSize++;
        }
    }

    void add(int x) {
        if (leftSize > 0 && x <= left.top()) {
            left.push(x);
            sum += x;
            leftSize++;
        } else {
            right.push(x);
        }
        balance();
    }

    void erase(int x) {
        delayed[x]++;
        if (leftSize > 0 && x <= left.top()) {
            sum -= x;
            leftSize--;
        }
        balance();
    }

    long long getSum() { return sum; }
};

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        Container cnt(k - 2);
        for (int i = 1; i < k - 1; i++) {
            cnt.add(nums[i]);
        }

        long long ans = cnt.getSum() + nums[k - 1];

        for (int i = k; i < n; i++) {
            int j = i - dist - 1;
            if (j > 0)
                cnt.erase(nums[j]);
            cnt.add(nums[i - 1]);
            ans = min(ans, cnt.getSum() + nums[i]);
        }

        return ans + nums[0];
    }
};
