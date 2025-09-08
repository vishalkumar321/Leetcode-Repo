// BRUTE FORCE APPROACH
// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int high = *max_element(piles.begin(), piles.end());

//         for (int k = 1; k < high; k++) {
//             long long hour = 0;
//             for (int pile : piles) {
//                 hour += (pile + k - 1) / k;
//             }
//             if (hour <= h) {
//                 return k;
//             }
//         }
//         return high;
//     }
// };

// OPTIMISED APPROACH
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            long long hour = 0;
            int mid = low + (high - low) / 2;

            for (int pile : piles) {
                hour += (pile + mid - 1) / mid;
            }

            if (hour <= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};