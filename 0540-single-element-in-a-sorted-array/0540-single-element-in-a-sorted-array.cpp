class Solution
{
    public:
        int singleNonDuplicate(vector<int> &nums)
        {
            if(nums.size() == 1) return nums[0];
            
            int left = 0, right = nums.size() - 1, res = -1;

            while (left <= right)
            {
               	// identifying index
                int mid = left + (right - left) / 2;
                int index = (mid % 2 == 0) ? mid + 1 : mid - 1;

               	// evaluation
                if (nums[mid] == nums[index])
                {
                    // pattern doesn't break until mid
                    left = mid + 1;
                }
                else
                {
                    // pattern has broken close the upper bound
                    right = mid - 1;
                }
            }
            return nums[left];
        }
};