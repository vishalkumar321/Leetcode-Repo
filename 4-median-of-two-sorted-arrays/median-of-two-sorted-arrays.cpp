class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i = 0;
        int j = 0;
        vector<int> merge;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                merge.push_back(nums1[i]);
                i++;
            } else if (nums1[i] > nums2[j]) {
                merge.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            merge.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size()) {
            merge.push_back(nums2[j]);
            j++;
        }

        int n = merge.size();

        if (n % 2 == 1) {
            return merge[n / 2];
        }
        return (merge[n / 2] + merge[n / 2 - 1]) / 2.0;
    }
};