class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if(nums.size() <= 1)
            return 0;
        // keep the count of the largest ladder we have
        int ladder = 0;
        // keep the count of number of stairs on each ladder
        int stairs = nums[0];
        int result = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            // if we reach the end don't need to move on with the stairs
            if(i == nums.size() - 1)
                return result;
            //  if we find a bigger ladder keep it until we run out of stairs      
            if(i + nums[i] > ladder)
            {
                ladder = i + nums[i];
            }
            stairs--;
            if(stairs == 0)
            {
                result++;
                stairs = ladder - i;
            }
        }
        return result;
    }
};