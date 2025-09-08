class Solution {
public:

       int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev(n),next(n);
        stack<int> s1,s2;

        // PREVIOUS SMALLER ELEMENTS
        for(int i=0; i<n; i++){
            while(s1.size()>0 && heights[s1.top()] >= heights[i]){
                s1.pop();
            }

            if(s1.empty()){
                prev[i] = -1;
            }else{
                prev[i] = s1.top();
            }
            s1.push(i);
        }

        // NEXT SMALLER ELEMENTS
        for(int i=n-1; i>=0; i--){
            while(s2.size()>0 && heights[s2.top()] >= heights[i]){
                s2.pop();
            }

            if(s2.empty()){
                next[i] = n;
            }else{
                next[i] = s2.top();
            }
            s2.push(i);
        }

        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int len = heights[i];
            int wid = next[i]-prev[i]-1;

            int newArea = len*wid;
            area = max(area, newArea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> heights(col,0);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j]== '0'){
                    heights[j]=0;
                }else{
                    heights[j]++;
                }
            }
             ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};