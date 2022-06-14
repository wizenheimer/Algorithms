class Solution {
public:
    void solve(int index,vector<int> &input,vector<int> output,vector<vector<int>> &result)
    {
        if(index >= input.size())
        {
            result.push_back(output);
            return;
        }
        int value = input[index];
        output.push_back(value);
        solve(index+1,input,output,result);
        output.pop_back();
        solve(index+1,input,output,result);
    }
    vector<vector<int>> subsets(vector<int>& input) {
        vector<vector<int>> result;
        vector<int> output;
        solve(0,input,output,result);
        return result;
    }
};