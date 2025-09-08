// OPTIMISED APPROACH
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};


// BRUTE FORCE APPROACH
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int i,j;
        
//         for(i=0;i<matrix.size();i++){
//             for(j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j]==target){
//                     return true;
//                     break;
//                 }
//             }
//         }
//         return false;
//     }
// };