class Solution {
public:
    void solve(int index,vector<int> &input,vector<int> output,vector<vector<int>> &result)
    {
        result.push_back(output);
        
        for(int i = index; i<input.size(); i++)
        {
            if(i != index && input[i] == input[i-1])
            {
                continue;
            }
            output.push_back(input[i]);
            solve(i+1, input, output, result);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& input) {
        vector<int> output;
        vector<vector<int>> result;
        sort(input.begin(),input.end());
        solve(0,input,output,result);
        return result;
    }
};