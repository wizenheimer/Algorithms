class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int targetRow = -1;
        int low = 0, high = row - 1;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(matrix[mid][0] > target) {
                high = mid - 1;
            }
            else if(matrix[mid][col - 1] < target) {
                low = mid + 1;
            }
            else {
                targetRow = mid;
                break;
            }
        }
        
        if (targetRow == -1) {
            return false;
        }
            
        low = 0, high = col - 1;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(matrix[targetRow][mid] < target) {
                low = mid + 1;
            }
            else if(matrix[targetRow][mid] > target) {
                high = mid - 1;
            }
            else {
                return true;
            }
        }
        
        return false;
    }
};