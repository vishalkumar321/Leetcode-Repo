class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> s1,s2;
        vector<int> next(n), prev(n);
        const int MOD = 1e9 + 7;

        for(int i = 0; i<n; i++){
            while(s1.size() > 0 && arr[s1.top()] > arr[i]){
                s1.pop();
            }
            if(s1.empty()){
                prev[i] = -1;
            }else{
                prev[i] = s1.top();
            }
            s1.push(i);
        }

        for(int i = n-1; i>=0; i--){
            while(s2.size() > 0 && arr[s2.top()] >= arr[i]){
                s2.pop();
            }
            if(s2.empty()){
                next[i] = n;
            }else{
                next[i] = s2.top();
            }
            s2.push(i);
        }

        long long res = 0;
        for(int i = 0; i<n; i++){

            long long left = i - prev[i];
            long long right = next[i] - i;

            res = (res+ (arr[i] *left % MOD)* right % MOD) % MOD;
        }
        return res;
    }
};