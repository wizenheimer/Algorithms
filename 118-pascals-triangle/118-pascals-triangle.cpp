class Solution {
public:
    void solve(int n, vector<vector<int>> &result)
    {
        result.push_back(vector(1,1));
        for(int i = 1; i < n; i++)
        {
            vector<int> arr;
            for(int j = 0; j <= i; j++)
            {
                if(j == 0 || j == i)
                {
                    arr.push_back(1);
                }
                else
                {
                    arr.push_back(result[i-1][j-1]+result[i-1][j]);
                }
            }
            result.push_back(arr);
        }
    }
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> result;
        solve(n,result);
        return result;
    }
};