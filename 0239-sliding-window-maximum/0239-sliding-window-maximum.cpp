class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
           	// maintain a decreasing queue
            deque<int> dq;
            vector<int> result;
            int n = nums.size();
            for (int left = 0, right = 0; right < n; right++)
            {
               	// get number
                int num = nums[right];

               	// pop numbers less than num
               	// push numbers in deque
                while (!dq.empty() && num > dq.back())
                    dq.pop_back();
                dq.push_back(num);

               	// move the window
                if (right - left == k-1)
                {
                    result.push_back(dq.front());
                    if(dq.front() == nums[left])
                        dq.pop_front();
                    left++;
                }
                // right++;
            }
            return result;
        }
};