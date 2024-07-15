class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        // transpose of matrix
       for(int i = 0 ;i<(row-1);i++) {
           for(int j = (i+1);j<row;j++){
               swap(matrix[i][j],matrix[j][i]);
           }
       }
    //    reverse that transpose matrix
              for(int i = 0 ;i<(row);i++) {
            reverse(matrix[i].begin(),matrix[i].end());
       }

    }
};