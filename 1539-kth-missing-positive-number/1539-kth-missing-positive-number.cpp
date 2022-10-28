class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {
            int low = 0, high = arr.size() - 1;
            auto result = -1;
            while (low <= high)
            {
                auto mid = low + (high - low) / 2;
                auto missingCount = arr[mid] - (mid + 1);

                if (missingCount < k)
                {
                    // re-adjust the low pointer
                    low = mid + 1;
                }
                else
                {
                    // re-adjust the high pointer
                    high = mid - 1;
                }
            }
            return low + k;
        }
};