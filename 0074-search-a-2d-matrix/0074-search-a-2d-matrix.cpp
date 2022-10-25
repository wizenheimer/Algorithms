class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int j = cols - 1, i = 0;
        
        while(j > -1 && i < rows) {
            int value = matrix[i][j];
            
            if(value == target)
                return true;
            else if(value > target) 
                j--;
            else 
                i++;
        }
        
        return false;
    }
};