class Solution
{
    private:
        int solve(vector<int> &nums, int k)
        {
            map<int, int> hash;
            int n = nums.size();
            int distinct = 0;
            int result = 0;
            for (int left = 0, right = 0; right < n; right++)
            {
               	// if number is distinct increment diff
                if (hash.find(nums[right]) == hash.end())
                    distinct++;
                
               	// add number in hash
                hash[nums[right]]++;
                
                
               	// if distinct <= k
                if (distinct <= k)
                {
                    result += right - left + 1;
                }
                else
                {
                    while (distinct > k)
                    {
                        hash[nums[left]]--;
                        if (hash[nums[left]] == 0)
                            hash.erase(nums[left]), distinct--;
                        left++;
                    }
                    result += right - left + 1;
                }
            }
            return result;
        }
    public:
        int subarraysWithKDistinct(vector<int> &nums, int k)
        {
            return solve(nums, k) - solve(nums, k - 1);
        }
};