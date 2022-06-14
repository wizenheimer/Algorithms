class Solution {
public:
    void Solve
        (int index, vector<int> &input, vector<int> output, int target, vector<vector<int>> &ans)
    {
//     base case
        if(index >= input.size())
        {
            if(target == 0)
            {
                ans.push_back(output);
            }
            return;
        }
        
//     pick condition
        if(input[index] <= target)
        {
            output.push_back(input[index]);
            Solve(index, input, output, target-input[index], ans);
            output.pop_back();
        }
//      don't pick condition
        Solve(index+1, input, output, target, ans);
     }
    vector<vector<int>> combinationSum(vector<int>& input, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        Solve(0,input,output,target,ans);
        return ans;
    }
};