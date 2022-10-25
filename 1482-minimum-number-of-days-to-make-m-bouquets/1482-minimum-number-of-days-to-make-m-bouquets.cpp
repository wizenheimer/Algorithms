class Solution
{
    public:
        bool isPossible(vector<int> &bloomDay, int day, int bqt, int flw)
        {
            int flower = 0;
            int bouquets = 0;

            for (int itr: bloomDay)
            {
               	// case for counting flowers
                if (itr <= day)
                    flower += 1;
                else
                    flower = 0;

               	// case for counting bqt
                if (flower >= flw)
                {
                    bouquets += 1;
                    flower = 0;
                }
            }

            return bouquets >= bqt;
        }

    int minDays(vector<int> &bloomDay, int m, int k)
    {

       	// base case
        if ((long long int) bloomDay.size() < (long long int) m * k) return -1;

       	// identify the search space low -> high
        int low = bloomDay[0], high = bloomDay[0];
        for (int i: bloomDay)
        {
            low = min(i, low);
            high = max(i, high);
        }

        int result = -1;

       	// identify in the search space
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(bloomDay, mid, m, k))
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