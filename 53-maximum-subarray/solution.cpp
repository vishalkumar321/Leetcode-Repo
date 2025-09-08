class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
       int currentSum = 0;
       int maxSum = INT_MIN;
       for(int i=0; i<nums.size(); i++){
            currentSum+= nums[i];
            maxSum = max(maxSum,currentSum);
            if(currentSum < 0){
                currentSum =0;
            }
       }
       return maxSum;
    }
};


// BRUTE FORCE APPROACH
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxSubarray =INT_MIN;
        
//         for(int i=0; i<nums.size(); i++){
//                 int sum=0;
//             for(int j=i; j<nums.size(); j++){
//                     sum = sum+nums[j];
//                     maxSubarray = max(maxSubarray, sum);
//             }
//         }
//         return maxSubarray;
//     }
// };