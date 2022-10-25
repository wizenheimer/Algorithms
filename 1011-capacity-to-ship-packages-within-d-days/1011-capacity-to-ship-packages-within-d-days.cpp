class Solution
{
    public:
        bool itsPossible(vector<int> &weights, int reqdays, int capacity)
        {
            int sum = 0;
            int days = 1;
            for (int weight: weights)
            {
                if (weight + sum <= capacity)
                {
                    sum += weight;
                }
                else
                {
                    days += 1;
                    sum = weight;
                }
            }
            
            // 
            return days <= reqdays;
        }

    int shipWithinDays(vector<int> &weights, int days)
    {
       	// build out the search space
        int low = weights[0], high = 0;
        for (auto weight: weights)
        {
            low = max(weight, low);
            high += weight;
        }
        
       	// perform binary search
        int result = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (itsPossible(weights, days, mid))
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
       	// return result
        return result;
    }
};