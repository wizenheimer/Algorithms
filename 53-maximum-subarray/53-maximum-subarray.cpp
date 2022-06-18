class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxL = nums[0];
        int maxG = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            maxL = max(nums[i]+maxL, nums[i]);
            maxG = max(maxL, maxG);
        }
        return maxG;
    }
};