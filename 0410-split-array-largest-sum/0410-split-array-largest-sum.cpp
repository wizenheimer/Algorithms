class Solution
{
    public:
       	// bool isPossible(vector<int> &arr, int subarrayCount, int barrier)
       	// {
       	//     auto count = 1, sum = 0;
       	//     for (auto element: arr)
       	//     {
       	//         if ((sum + element) <= barrier)
       	//         {
       	//             sum += element;
       	//         }
       	//         else
       	//         {
       	//             subarrayCount += 1;
       	//             sum = element;
       	//         }
       	//     }
       	//     return count <= subarrayCount;
       	// }

        bool isPossible(vector<int> &nums,int m, int mid)
        {
            int count = 1, tempsum = 0, n = nums.size();
            for (int i = 0; i < n; ++i)
            {
                if (tempsum + nums[i] <= mid) tempsum += nums[i];
                else count++, tempsum = nums[i];
            }
            // count++;

            return count <= m;
        }

    int splitArray(vector<int> &arr, int k)
    {
        auto low = arr[0], high = 0;
        for (auto element: arr)
        {
            low = max(low, element);
            high += element;
        }

        auto result = -1;
        while (low <= high)
        {
            auto mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid))
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return result;
    }
};