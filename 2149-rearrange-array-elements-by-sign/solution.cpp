class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int posIdx =0;
        int negIdx =1;
        int n = nums.size();
        vector<int> result(n);

        for(int i=0; i<n ; i++){
            if(nums[i]>0){
                result[posIdx]=nums[i];
                posIdx+=2;
            }
            else{
                result[negIdx]=nums[i];
                negIdx+=2;
            }
        }
        return result;
    }
};


// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
        
//         vector<int> positive;
//         vector<int> negative;
//         vector<int> result;
//         int n= nums.size();

//         for(int i=0; i<n; i++){
//             if(nums[i]>0){
//                 positive.push_back(nums[i]);
//             }
//             else{
//                 negative.push_back(nums[i]);
//             }
//         }
//         for(int i=0; i<n/2; i++){
//                 result.push_back(positive[i]);
//                 result.push_back(negative[i]);
//         }
//         return result;
//     }
// };