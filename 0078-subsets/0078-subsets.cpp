class Solution {
private:
    void solve(int index, vector<int> nums, vector<int> subset, vector<vector<int>> &result) 
    {
        if(index == nums.size())
        {
            result.push_back(subset);
            subset.clear();
            return;
        }
        
        subset.push_back(nums[index]);
        solve(index+1, nums, subset, result);
        
        subset.pop_back();
        solve(index+1, nums, subset, result);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> subset;
        
        solve(0, nums, subset, result);
        
        return result;
    }
};