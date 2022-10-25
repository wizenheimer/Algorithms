class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search solution
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = rows * cols - 1;
        
        while(left <= right) {
            int mid = left + (right - left)/2;
            int current = matrix[mid/cols][mid%cols];
            
            if(current == target) 
                return true;
            else if(target < current) 
                right = mid - 1;
            else 
                left = mid + 1;
        }
        
        return false;
    }
};