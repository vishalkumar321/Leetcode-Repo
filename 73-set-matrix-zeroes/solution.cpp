// BETTER APPROACH
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int> row(n,0);
        vector<int> col(m,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i] || col[j]){
                   matrix[i][j]=0;
                }
            }
        }
    }
};


// BRUTE FORCE APPROACH
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int row = matrix.size();
//         int col = matrix[0].size();
//         int pos1,pos2;

//         for(int i=0; i<row; i++){
//             for(int j=0; j<col; j++){
//                 if(matrix[i][j]==0){
//                     pos1 =i;
//                     pos2 =j;
//                 }
//             }
//         }
//         for(int i=pos1; i<=pos1; i++){
//             for(int j=0; j<col; j++){
//                 matrix[i][j]=0;
//             }
//         }
//         for(int i=0; i<row; i++){
//             for(int j=pos2; j<=pos2; j++){
//                 matrix[i][j]=0;
//             }
//         }
//     }
// };