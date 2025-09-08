// OPTIMAL APPROACH
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        int n = nums.size();
        if(n==0)return 0;
        int maxCount = 1;

        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        for(auto it: st){
            if(st.find(it-1) == st.end()){
                int count =1;
                int x = it;
                while(st.find(x+1)!=st.end()){
                    x= x+1;
                    count+= 1;
                }
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};

// BETTER APPROACH
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         sort(nums.begin(),nums.end());

//         int n = nums.size();
//         if(n==0)return 0;
//         int count=1;
//         int maxCount = 1;

//         for(int i=1; i<n; i++){
//             if(nums[i]==nums[i-1]+1){
//                 count++;
//             }
//             else if(nums[i]==nums[i-1]){
//                 continue;
//             }
//             else{
//                 count=1;
//             }
//             maxCount = max(maxCount,count);
//         }
//         return maxCount;
//     }
// };