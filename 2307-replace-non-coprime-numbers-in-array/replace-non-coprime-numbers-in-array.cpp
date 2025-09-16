class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;
        for (int x : nums) {
            long long cur = x;
            while (!st.empty()) {
                long long g = __gcd(st.back(), cur);
                if (g == 1)
                    break;
                cur = lcm(st.back(), cur);
                st.pop_back();
            }
            st.push_back(cur);
        }
        vector<int> res(st.begin(), st.end());
        return res;
    }
};