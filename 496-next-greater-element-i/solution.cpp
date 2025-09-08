// O(n**2) APPROACH

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            int found = false;
            int nextGreater = -1;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    found = true;
                } else if (found && nums2[j] > nums1[i]) {
                    nextGreater = nums2[j];
                    break;
                }
            }
            ans.push_back(nextGreater);
        }
        return ans;
    }
};


// O(n**3) COMPLEXITY OR BRUTE FORCE APPROACH

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

//         vector<int> ans;
//         for (int i = 0; i < nums1.size(); i++) {
//             int found = -1;
//             for (int j = 0; j < nums2.size(); j++) {
//                 if (nums1[i] == nums2[j]) {
//                     for (int k = j + 1; k < nums2.size(); k++) {
//                         if (nums2[j] < nums2[k]) {
//                             found = nums2[k];
//                             break;
//                         }
//                     }
//                     break;
//                 }
//             }
//             ans.push_back(found);
//         }
//         return ans;
//     }
// };


// OPTIMAL SOLUTION O(n+m) COMPLEXITY

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> m;
//         stack<int> s;

//         for (int i = nums2.size() - 1; i >= 0; i--) {
//             while (s.size() > 0 && nums2[i] >= s.top()) {
//                 s.pop();
//             }
//             if (s.empty()) {
//                 m[nums2[i]] = -1;
//             } else {
//                 m[nums2[i]] = s.top();
//             }
//             s.push(nums2[i]);
//         }

//         vector<int> ans;

//         for (int i = 0; i < nums1.size(); i++) {
//             ans.push_back(m[nums1[i]]);
//         }
//         return ans;
//     }
// };