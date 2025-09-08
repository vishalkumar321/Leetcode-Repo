class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int f_max = *max_element(freq.begin(), freq.end());

        int max_count = count(freq.begin(), freq.end(), f_max);

        int intervals = (f_max - 1) * (n + 1) + max_count;

        return max((int)tasks.size(), intervals);
    }
};