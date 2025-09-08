class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int majority =nums.size()/2;
        int ans=nums[0];
        int freq =1;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                freq++;
            }
            else{
                freq=1;
                ans=nums[i];
            }
            if(majority<freq){
                    return ans;
                }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//       int majority =nums.size()/2;
//       int ans=0;
//       for(int i=0; i<nums.size(); i++){
//             int freq=0;
//             for(int j=0; j<nums.size(); j++){
//                 if(nums[i]==nums[j]) freq++;
//                 if(majority<freq){
//                     ans=nums[i];
//                 }
//             }
            
//       }
//     return ans;
//     }
// };