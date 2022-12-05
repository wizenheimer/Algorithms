class Solution
{
    private:
        int solve(vector<int> &nums, int k)
        {
            int n = nums.size();
            int result = 0;
            int odd = 0;
            for (int left = 0, right = 0; right < n; right++)
            {
                if (nums[right] % 2 != 0)
                {
                    odd++;
                }
                if (odd <= k)
                {
                    result += right - left + 1;
                }
                else
                {
                    while (odd > k)
                    {
                        if (nums[left] % 2 != 0)
                            odd--;
                        left++;
                    }
                    result += right - left + 1;
                }
            }
            return result;
        }
    public:
        int numberOfSubarrays(vector<int> &nums, int k)
        {
            return solve(nums, k) - solve(nums, k - 1);
        }
};