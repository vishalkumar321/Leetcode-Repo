class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
                low++;
                mid++; 
        }

        else if(nums[mid]==1){
            mid++;
        }

        else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
                high--;
            } 
        }
    }
};


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//        int count1 = 0;
//        int count2 = 0;
//        int count3 = 0;

//        for(int i=0; i<nums.size(); i++){
//         if(nums[i]==0) count1++;
//         if(nums[i]==1) count2++;
//         if(nums[i]==2) count3++;
//        }
       
//        for(int i=0;i<count1;i++){
//         nums[i]=0;
//        }
//        for(int i=count1;i<count1+count2;i++){
//         nums[i]=1;
//        }
//        for(int i=count1+count2;i<count1+count2+count3;i++){
//         nums[i]=2;
//        }
//     }
// };


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         for(int i=0; i<nums.size()-1; i++){
//             for(int j=i+1; j<nums.size();j++){
//                 if(nums[i]>nums[j]){
//                     swap(nums[i],nums[j]);
//                 }
//             }
//         }
//     }
// };


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//     }
// };