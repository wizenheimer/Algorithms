class Solution
{
    public:
        bool works(vector<int> &piles, int mid, int h)
        {
            long int netHours = 0;
            for(int banana: piles)
            {
                netHours += banana / mid;
                if (banana % mid != 0)
                    netHours++;
                
                if(netHours > h)
                    return false;
            }
            
            return true;
        }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // optimization
        int left = 1, right = 1000000000;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (works(piles, mid, h))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;

       	//        	// calculate the maximum in the pile
       	//         int maxVal = piles[0];
       	//         for(int i = 0; i < piles.size(); i++) {
       	//             maxVal = max(maxVal, piles[i]);
       	//         }

       	//        	// result counter
       	//         int res = maxVal;

       	//        	// create an array and prefill with values
       	//         vector<int> arr(maxVal);
       	//         std::iota(arr.begin(), arr.end(), 1);

       	//         int low = 0, high = arr.size() - 1;
       	//         while(low <= high) {
       	//             int mid = low + (high - low)/2;

       	//            	// calculate net hours required to eat the pile
       	//             long int netHours = 0;
       	//             for(int pile : piles) {
       	//                 netHours += pile/arr[mid];

       	//                 if (pile % arr[mid] > 0) 
       	//                     netHours++;
       	//             }

       	//            	// if nethours fits the condition
       	//             if(netHours <= h) {
       	//                 res = min(res, arr[mid]);
       	//                 high = mid - 1;
       	//             } else {
       	//                 low = mid + 1;
       	//             }
       	//         }
       	//         return res;
    }
};