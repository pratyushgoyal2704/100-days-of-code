class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows==0||cols==0) return;
        dp.resize(rows,vector<int>(cols,0));
        dp[0][0] = matrix[0][0];
        for(int i=1;i<rows;i++){
            dp[i][0] = matrix[i][0] + dp[i-1][0];
        }
        for(int j=1;j<cols;j++){
            dp[0][j] = matrix[0][j] + dp[0][j-1];
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] + matrix[i][j] - dp[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2][col2]  - (col1-1>=0?dp[row2][col1-1]:0) - (row1-1>=0?dp[row1-1][col2]:0) + ((row1-1>=0 && col1-1>=0)?dp[row1-1][col1-1]:0);
       
    }
};
