class Solution {
  public:
   vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        int n = matrix.size();
        vector<int> ans;
        
        // first part
        for(int j = 0; j < n; j++){
            for(int x = 0, y = j; y > -1 and x < n; x++, y--){
                ans.push_back(matrix[x][y]);
            }
        }
        
        // second part
        for(int i = 1; i < n; i++){
            for(int y = n - 1, x = i; y > -1 and x < n; x++, y--){
                ans.push_back(matrix[x][y]);
            }
        }
        
        return ans;
    }
};
