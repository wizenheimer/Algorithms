class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;
        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;
        
        vector<int> result;
        
        while(rowBegin <= rowEnd && colBegin <= colEnd)
        {
            // traverse right
            for(int i = colBegin; i <= colEnd; i++)
                result.push_back(matrix[rowBegin][i]);
            rowBegin++;
            // traverse bottom
            for(int i = rowBegin; i <= rowEnd; i++)
                result.push_back(matrix[i][colEnd]);
            colEnd--;
            // traverse left
            if(rowBegin <= rowEnd)
            {
                for(int i = colEnd; i >= colBegin; i--)
                    result.push_back(matrix[rowEnd][i]);
                rowEnd--;   
            }
            // traverse upwards
            if(colBegin <= colEnd)
            {
                for(int i = rowEnd; i >= rowBegin; i--)
                    result.push_back(matrix[i][colBegin]);
                colBegin++;   
            }            
        }
        
        return result;
    }
};