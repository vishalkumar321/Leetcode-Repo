class Solution {
public:
    multiset<int> left, right;

    void balance() {
        
        while (left.size() > right.size() + 1) {
            auto it = prev(left.end()); 
            right.insert(*it);
            left.erase(it);
        }

        while (left.size() < right.size()) {
            auto it = right.begin(); 
            left.insert(*it);
            right.erase(it);
        }
    }

    void insert(int x) {
        if (left.empty() || x <= *prev(left.end()))
            left.insert(x);
        else
            right.insert(x);

        balance();
    }

    void remove(int x) {
        auto it = left.find(x);

        if (it != left.end())
            left.erase(it);
        else
            right.erase(right.find(x));

        balance();
    }

    double median(int k) {
        if (k % 2)
            return (double)(*prev(left.end()));

        return ((double)(*prev(left.end())) + (double)(*right.begin())) / 2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;

        for (int i = 0; i < k; i++)
            insert(nums[i]);

        ans.push_back(median(k));

        for (int i = k; i < nums.size(); i++) {
            remove(nums[i - k]);
            insert(nums[i]);
            ans.push_back(median(k));
        }

        return ans;
    }
};