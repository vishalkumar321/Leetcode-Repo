// OPTIMAL APPROACH
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = -1, last = -1;
        int start = 0;
        int end = nums.size()-1;

        while(start<=end){
            int mid = start + (end - start) / 2;

            if(nums[mid]==target){
                first = mid;
                end = mid-1; 
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        start = 0;
        end = nums.size()-1;
        
        while(start<=end){
            int mid = start + (end - start) / 2;

            if(nums[mid]==target){
                last = mid;
                start = mid+1; 
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return {first,last};
    }
};


// BRUTE FORCE APPROACH
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int startingPosition = -1, endingPosition = -1;
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             if(nums[i] == target){
//                 startingPosition = i;
//                 break;
//             }
//         }
//         for(int i=n-1; i>=0; i--){
//             if(nums[i] == target){
//                 endingPosition = i;
//                 break;
//             }
//         }
//         return {startingPosition, endingPosition};
//     }
// };