class Solution
{
    private:
        void solve(int index, vector<int> nums, set<vector<int>> &result)
        {
            if (index >= nums.size())
            {
                result.insert(nums);
                return;
            }

            for (int i = index; i < nums.size(); i++)
            {
                swap(nums[index], nums[i]);
                solve(index + 1, nums, result);
                swap(nums[index], nums[i]);
            }
        }

    public:
        vector<vector < int>> permuteUnique(vector<int> &nums)
        {
            set<vector < int>> result;
            solve(0, nums, result);

            vector<vector < int>> ans;
            for (auto itr = result.begin(); itr != result.end(); itr++)
            {
                ans.push_back(*itr);
            }

            return ans;
        }
};