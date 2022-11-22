class Solution
{
    public:
        int trap(vector<int> &height)
        {
            int left = 0, right = height.size() - 1;
            int maxLeft = INT_MIN, maxRight = INT_MIN;
            int res = 0;
            while (left <= right)
            {
                if (height[left] < height[right])
                {
                    if (maxLeft < height[left])
                        maxLeft = height[left];
                    else
                        res += maxLeft - height[left];
                    left++;
                }
                else
                {
                    if (maxRight < height[right])
                        maxRight = height[right];
                    else
                        res += maxRight - height[right];
                    right--;
                }
            }
            return res;
        }
};