class Solution {
public:
    void solve(int index,vector<int> &input, vector<vector<int>> &result)
    {
        if(index >= input.size())
        {
            result.push_back(input);
            return;
        }
        for(int i = index; i < input.size(); i++)
        {
//             tryout every element at each position
//             do swap
            swap(input[index],input[i]);
            solve(index+1,input,result);
//             undo swap
            swap(input[index],input[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& input) {
        vector<vector<int>> result;
        solve(0,input,result);
        return result;
    }
};