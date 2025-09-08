class Solution {
public:
    int findLucky(vector<int>& arr) {

        int freq[501] = {0};

        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }

        for (int i = 500; i > 0; i--) {
            if (freq[i] == i)
                return i;
        }
        return -1;
    }
};