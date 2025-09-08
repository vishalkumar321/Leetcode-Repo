// OPTIMISED APPROACH
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;
        int right = n - 1;
        int k = n + m - 1;

        while (left >= 0 && right >= 0) {
            if (nums1[left] > nums2[right]) {
                nums1[k] = nums1[left];
                k--;
                left--;
            } else {
                nums1[k] = nums2[right];
                k--;
                right--;
            }
        }

        while (right >= 0) {
            nums1[k--] = nums2[right--];
        }
    }
};


// BETTER APPROACH
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> arr(n + m);
//         int left = 0;
//         int right = 0;
//         int index = 0;

//         while (left < m && right < n) {
//             if (nums1[left] < nums2[right]) {
//                 arr[index] = nums1[left];
//                 index++;
//                 left++;
//             } else {
//                 arr[index] = nums2[right];
//                 index++;
//                 right++;
//             }
//         }

//         while (left < m) {
//             arr[index] = nums1[left];
//             index++;
//             left++;
//         }

//         while (right < n) {
//             arr[index] = nums2[right];
//             index++;
//             right++;
//         }

//         for (int i = 0; i < n + m; i++) {
//             nums1[i] = arr[i];
//         }
//     }
// };


// OPTIMISED APPROACH
// class Solution {
// public:
//     void swapIfGreater(vector<int>& nums1, int index1, vector<int>& nums2, int index2){
//         if(nums1[index1]>nums2[index2]){
//             swap(nums1[index1],nums2[index2]);
//         }
//     }

//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int len = (n+m);
//         int gap = (len/2)+(len%2);

//         while(gap>0){
//             int left = 0;
//             int right = gap;

//             while(right<len){
//                 if(left<m && right<m){
//                     swapIfGreater(nums1,left, nums1, right);
//                 }
//                 else if(left<m && right>=m){
//                     swapIfGreater(nums1,left , nums2, right-m);
//                 }
//                 else{
//                     swapIfGreater(nums2,left-m, nums2, right-m);
//                 }
//                 left++;
//                 right++;
//             }
//             if(gap==1)break;
//             gap = (gap/2)+(gap%2);
//         }
//         for(int i = 0; i < n; i++){
//             nums1[m+i] = nums2[i];
//         }
//     }
// };

