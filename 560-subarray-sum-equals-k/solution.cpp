class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int n= nums.size();
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n;j++){
                sum+= nums[j];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
    }
};



// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count=0;
//         int n= nums.size();
//         for(int i=0; i<n; i++){
//             for(int j=i; j<n;j++){
//                     int sum=0;
//                 for(int l=i;l<=j;l++){
//                     sum+= nums[l];
//                 }
//                 if(sum==k){
//                     count++;
//                 }

//             }
//         }
//         return count;
//     }
// };