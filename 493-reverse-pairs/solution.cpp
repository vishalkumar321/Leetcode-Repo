// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;
//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 if(nums[i]>2*nums[j]){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int mergesort(vector<long long>& nums, int left, int right) {
        if (left >= right)
            return 0;

        int mid = (left + right) / 2;
        int count =
            mergesort(nums, left, mid) + mergesort(nums, mid + 1, right);

        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        vector<long long> temp;
        int i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while (i <= mid)
            temp.push_back(nums[i++]);
        while (j <= right)
            temp.push_back(nums[j++]);

        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        vector<long long> arr(nums.begin(), nums.end());
        return mergesort(arr, 0, nums.size() - 1);
    }
};