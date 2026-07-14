class Solution {
public:
    int balancedString(string s) {
        int n = s.size();

        int required = n / 4;

        unordered_map<char, int> count;

        for (auto& it : s) {
            count[it]++;
        }

        if (count['Q'] <= required && count['W'] <= required &&
            count['E'] <= required && count['R'] <= required) {
            return 0;
        }

        int ans = n;
        int left = 0;

        for (int right = 0; right < n; right++) {
            count[s[right]]--;

            while (left <= right && count['Q'] <= required &&
                   count['W'] <= required && count['E'] <= required &&
                   count['R'] <= required) {

                ans = min(ans, right - left + 1);

                count[s[left]]++;
                left++;
            }
        }
        return ans;
    }
};