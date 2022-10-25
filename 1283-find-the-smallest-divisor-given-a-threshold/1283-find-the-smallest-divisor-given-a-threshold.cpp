class Solution
{
    public:
       	//         bool isPossible(vector<int> &nums, int threshold, int divisor)
       	//         {

       	//            	// evaluate the result
       	//             int result = 0;
       	//             for (int i: nums)
       	//             {

       	//                 result += i / divisor;

       	//                 if (i % divisor != 0)
       	//                     result += 1;
       	//             }

       	//            	// test case
       	//             return result <= threshold;
       	//         }
        int smallestDivisor(vector<int> &nums, int threshold)
        {
            int l = 1, r = 1e6+1;
            int ans = 0;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                long long int sum = 0;
                for (int i = 0; i < nums.size(); i++)
                {
                    if (nums[i] % mid == 0)
                    {
                        sum += (nums[i] / mid);
                    }
                    else
                    {
                        sum += (nums[i] / mid) + 1;
                    }
                }
                if (sum > threshold)
                {
                    l = mid + 1;
                }
                else
                {
                    ans = mid;
                    r = mid - 1;
                }
            }
            return ans;
           	//        	// identify the search space 
           	//         int low, high;
           	//         for (int i: nums)
           	//         {
           	//             low = min(i, low);
           	//             high = max(i, high);
           	//         }

           	//        	// binary search
           	//         int result = 0;
           	//         while (low <= high)
           	//         {
           	//             int mid = low + (high - low) / 2;
           	//             if (isPossible(nums, threshold, mid))
           	//             {
           	//                 result = mid;
           	//                 high = mid - 1;
           	//             }
           	//             else
           	//             {
           	//                 low = mid + 1;
           	//             }
           	//         }

           	//        	// return result
           	//         return result;
        }
};