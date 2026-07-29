class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (auto& it : asteroids) {
            bool destroyed = false;

            while (!st.empty() && it < 0 && st.top() > 0) {
                if (st.top() == -it) {
                    st.pop();
                    destroyed = true;
                    break;
                } else if (st.top() < -it) {
                    st.pop();
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                st.push(it);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};