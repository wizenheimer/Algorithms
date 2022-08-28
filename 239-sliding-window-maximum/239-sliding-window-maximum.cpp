class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
            vector<int> result;

            deque<int> dq;
            // hold indices

            int left = 0, right = 0;

            while (right < nums.size())
            {
                while(!dq.empty() && nums[dq.back()] < nums[right])
                {
                    dq.pop_back();
                }
                dq.push_back(right);
                
                if(right - left + 1 < k)
                {
                   right++;
                }
                else if(right - left + 1 == k)
                {
                    result.push_back(nums[dq.front()]);
                    
                    if(dq.front() == left)
                        dq.pop_front();
                    
                    
                    left++;
                    right++;                    
                }
            }

            return result;
        }
};