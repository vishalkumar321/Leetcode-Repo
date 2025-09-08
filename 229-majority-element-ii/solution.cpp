// BETTER APPROACH
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> freq;
//         vector<int>result;

//         for(int i=0; i<n; i++){
//             freq[nums[i]]++;
//         }
//         for(auto& [num,count] : freq){
//             if(n/3<count){
//                 result.push_back(num);
//             }
//         }
//         return result;
//     }
// };

// OPTIMAL APPROACH
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 && ele2 != nums[i]) {
                cnt1 = 1;
                ele1 = nums[i];
            } else if (cnt2 == 0 && ele1 != nums[i]) {
                cnt2 = 1;
                ele2 = nums[i];
            } else if (ele1 == nums[i])
                cnt1++;
            else if (ele2 == nums[i])
                cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (ele1 == nums[i])
                cnt1++;
            if (ele2 == nums[i])
                cnt2++;
        }
        int mini = (nums.size() / 3) + 1;
        if (cnt1 >= mini)
            ans.push_back(ele1);
        if (cnt2 >= mini)
            ans.push_back(ele2);
        return ans;
    }
};